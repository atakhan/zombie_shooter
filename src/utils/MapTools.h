#ifndef SRC_UTILS_MAP_TOOLS_H
#define SRC_UTILS_MAP_TOOLS_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "../Config.h"
#include "../core/Bootstrap.h"
#include "../components/Bootstrap.h"
#include "../systems/Bootstrap.h"

class MapTools {  
  public:
    // CREATE GAME
    static Entity* CreateMap(float width, float height, float cellWidth, float cellHeight) {
        Entity *map = new Entity();
        map->AddComponent<TerrainComponent>(TerrainComponent(
            width, 
            height,
            cellWidth,
            cellHeight
        ));

        std::vector<std::vector<int>> binaryArray = ParseMap("../src/maps/test.txt");

        // Вывод результата для проверки
        for (const auto& row : binaryArray) {
            for (int value : row) {
                std::cout << value << " ";
            }
            std::cout << std::endl;
        }

        return map;
    }

    static std::vector<std::vector<int>> ParseMap(std::string filepath) {
        std::ifstream file(filepath);
        std::vector<std::vector<int>> array;
        std::string line;

        if (!file.is_open()) {
            std::cerr << "Не удалось открыть файл: " << filepath << std::endl;
            return array; // Вернуть пустой массив в случае ошибки
        }

        while (std::getline(file, line)) {
            std::vector<int> row;
            for (char ch : line) {
                if (ch == '0' || ch == '1') {
                    row.push_back(ch - '0'); // Преобразуем символ в целое число
                }
            }
            array.push_back(row);
        }

        file.close();
        return array;
    }
};

#endif // SRC_UTILS_MAP_TOOLS_H