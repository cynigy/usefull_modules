#pragma once
// Автор Тюлькина И.П.
// Работа с файлами

enum Files {
  OVERWRITE, 
  NEW,
  ARR,
};

//поиск имени для ввода исходных данных
void InputDataFromFile(std::string& filename);

//поиск имени для сохранение данных в файл
void SaveTheDataAndСhecking(std::string& filename);
