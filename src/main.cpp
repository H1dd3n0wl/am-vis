#include <AtanorArtifactDAO.hpp>
#include <AtanorCountryDAO.hpp>
#include <AtanorCreatureCountryDAO.hpp>
#include <AtanorCreatureDAO.hpp>
#include <AtanorHorseDAO.hpp>
#include <filesystem>
#include <fstream>
#include <tools/string_tools.hpp>

using path = std::filesystem::path;

int main(int argc, char* argv[]) {

    // std::string table_name = "AtanorCountry";

    // std::string create_table_query = sql_tools::sql_create_table(
    //     table_name, "Название text", "Раса text", "Деньги int", "Войско int",
    //     "Магия int", "Техника int", "Дружба int", "Ресурсы int", "Место
    //     text", "Столица text", "Суть text");

    // std::cout << create_table_query << '\n';

    path upper_source_dir =
        std::filesystem::current_path().parent_path().parent_path();
    path db_path = upper_source_dir / "db\\test.db";

    // dao::AtanorArtifactDAO controller1(db_path.string());
    // dao::AtanorCountryDAO controller2(db_path.string());
    // dao::AtanorHorseDAO controller3(db_path.string());
    // dao::AtanorCreatureDAO controller4(db_path.string());

    // controller1.create_table();
    // controller2.create_table();
    // controller3.create_table();
    // controller4.create_table();

    dao::AtanorCreatureCountryDAO controller5(db_path.string());

    controller5.create_table();
}