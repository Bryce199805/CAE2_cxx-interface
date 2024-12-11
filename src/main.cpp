//
// Created by Bryce on 24-9-27.
//

#include <iostream>
#include "CAE.h"
#include "DBVariant.h"

int main() {
    CAE obj("../config.yaml", true);

    // ip ����
    // ��ѯ����
    // std::string query_sql = "select * from BASIC_SHIP_INFORMATION_DB.SHIP_DATA_INFO where ship_type = '�ʹ�'";
    // std::vector<std::vector<DBVariant> > result2;
    // std::vector<int> col_types;
    //
    // if (obj.Query(query_sql, result2, col_types)) {
    //     // �����ӡ����
    //     obj.printResult(result2, col_types);
    // }

    // �������
    // std::string insert_sql =
    //         "insert into BASIC_SHIP_INFORMATION_DB.SISTER_SHIP_INFO (SHIP_DATA_ID, SISTER_DATA_ID, SHIP_NAME) "
    //         "values (7082006, 7082007, 'test No1')";
    // if (obj.Insert(insert_sql)) {
    //     std::cout << "insert done." << std::endl;
    // }

    // ���²���
    // std::string update_sql = "update BASIC_SHIP_INFORMATION_DB.SISTER_SHIP_INFO set SHIP_NAME = 'test No1' where SHIP_NAME = 'test No3'";
    // if (obj.Update(update_sql)) {
    //     std::cout << "update done." << std::endl;
    // }
    //
    // //ɾ������
    // std::string delete_sql = "delete from BASIC_SHIP_INFORMATION_DB.SISTER_SHIP_INFO where SHIP_NAME = 'test No1'";
    // if (obj.Delete(delete_sql)) {
    //     std::cout << "delete done." << std::endl;
    // }


    //�ļ���������

    // //�ϴ��ļ� ָ��·�������ļ��� hull_parameter_info
    // if (obj.UploadFile("hull_model_and_information_db", "hull_parameter_info", "SampleShip_JBC0000", "TRANSVERSE_AREA_CURVE", "../doc/����.png")) {
    //     std::cout << "Upload file done." << std::endl;
    // }
    // if (obj.UploadFile("hull_model_and_information_db", "hull_parameter_info", "SampleShip_JBC0000", "HULL_3D_MODEL",
    //                    "../doc/sharks.png")) {
    //     std::cout << "Upload file done." << std::endl;
    // }
    // // �����ļ� ָ��·���������ļ���
    // if (obj.GetFile("hull_model_and_information_db", "HULL_PARAMETER_INFO", "SampleShip_JBC0000",
    //                 "TRANSVERSE_AREA_CURVE", ".")) {
    //     std::cout << "Download file done." << std::endl;
    // }
    //
    //�����ַ���
    std::vector<unsigned char> object_data;
    if (obj.GetFile("HuLL_MODEL_AND_INFORMATION_Db", "hull_parameter_info", "SampleShip_JBC0000", "HULL_3D_MODEL",
                    object_data)) {
        std::cout << "Download data stream done." << std::endl;
        std::cout << "object_data size: " << object_data.size() << std::endl;
    }
    //
    // // ɾ���ļ�
    // if (obj.DeleteFile("HULL_MODEL_AND_INFORMATION_DB", "hull_parameter_info", "SampleShip_JBC0000",
    //                    "TRANSVERSE_AREA_CURVE")) {
    //     std::cout << "Delete file done." << std::endl;
    // }
    //
    // //ɾ����¼
    // if (obj.DeleteRecord("hull_model_and_information_db", "Performance_info", "SampleShip_JBC0000")) {
    //     std::cout << "Delete record done." << std::endl;
    // }

    return 0;
}
