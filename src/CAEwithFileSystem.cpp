//
// Created by Bryce on 24-11-19.
//

#include "CAE.h"

#ifdef USE_FILESYSTEM

// constructor

CAE::CAE(const std::string &file_path, bool withFile) {
    if(withFile) {
        this->initDB_(file_path);

        // todo init file system
    }
    else {
        this->initDB_(file_path);
    }
}

// private function


// public function




#endif
