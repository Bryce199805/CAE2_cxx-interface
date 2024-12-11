/*
 * Use and distribution licensed under the Apache license version 2.
 *
 * See the COPYING file in the root project directory for full text.
 */

#include <iostream>

#include "node.h"
#include "printer.h"

namespace sqltoaster {
    bool flag = false;

    void print_map(std::ostream& out, const mapping_t& mapping, size_t indent_level, bool is_list_item) {
        for (const std::unique_ptr<const mapping_value_t>& el : mapping.elements) {
            if (!is_list_item) {
                if (indent_level > 0)
                    out << std::endl;
                out << std::string(indent_level * 2, ' ');
            }
            else {
                out << std::endl << std::string((indent_level - 1) * 2, ' ') << "- ";
                is_list_item = false;
            }

            switch (el->value->type) {
            case SCALAR: {
                const scalar_t& sub =
                    static_cast<const scalar_t&>(*el->value);
                out << el->key << ":" << sub.value;

                if (sub.value == "TABLE") {
                    flag = true;
                    out << "tag";
                }

                if (el->key == "name" && flag) {
                    out << "got it.";
                    flag = false;
                }
            }
            break;
            case MAPPING: {
                const mapping_t& sub =
                    static_cast<const mapping_t&>(*el->value);
                out << el->key << ":";
                print_map(out, sub, indent_level + 1, false);
            }
            break;
            case SEQUENCE: {
                const sequence_t& sub =
                    static_cast<const sequence_t&>(*el->value);
                out << el->key << ":";

                for (const std::unique_ptr<node_t>& list_el : sub.elements) {
                    if (list_el->type == SCALAR) {
                        const scalar_t& sub =
                            static_cast<const scalar_t&>(*list_el);
                        out << std::endl << std::string((indent_level + 1) * 2, ' ') << "- ";
                        out << sub.value;
                    }
                    else if (list_el->type == MAPPING) {
                        const mapping_t& sub =
                            static_cast<const mapping_t&>(*list_el);
                        print_map(out, sub, indent_level + 2, true);
                    }
                }
            }
            break;
            }
        }
    }

    void get_table(const mapping_t& mapping, std::vector<std::string>& res) {
        for (const std::unique_ptr<const mapping_value_t>& el : mapping.elements) {
            switch (el->value->type) {
            case SCALAR: {
                const scalar_t& sub = static_cast<const scalar_t&>(*el->value);
                if (sub.value == "TABLE") {
                    flag = true;
                }
                if (el->key == "name" && flag) {
                    res.push_back(sub.value);
                    flag = false;
                }
            }
            break;

            case MAPPING: {
                const mapping_t& sub = static_cast<const mapping_t&>(*el->value);
                get_table(sub, res);
            }
            break;

            case SEQUENCE: {
                const sequence_t& sub = static_cast<const sequence_t&>(*el->value);
                for (const std::unique_ptr<node_t>& list_el : sub.elements) {
                    if (list_el->type == MAPPING) {
                        const mapping_t& sub = static_cast<const mapping_t&>(*list_el);
                        get_table(sub, res);
                    }
                }
                break;
            }
            }
        }
    }
} // namespace sqltoaster
