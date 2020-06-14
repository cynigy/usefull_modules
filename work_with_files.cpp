// Автор: Тюлькина Ирина Павловна 
// Работа с файлами
#include <iostream> 
#include <Windows.h>
#include <fstream>
#include <filesystem> 
// модуль пользовательского интерфеса,
//где Foolproof() - функция для проверки пользовательского ввода
#include "user_interface.h" 
#include <string>

using namespace std::filesystem;
using namespace std;

enum Files {
  OVERWRITE,
  NEW,
};

//Проверка на возможность существование файла
bool Filenamecheck(string filename) {
  size_t found = filename.find_last_of("\\");
  size_t point = filename.find_last_of(".");
  size_t base = point - found - 1;
  string basefilenameStr = filename.substr(found + 1, base);
  const char* basefilenameChar = basefilenameStr.c_str();
  ofstream file(filename, ios::app);
  if (!_strcmpi(basefilenameChar, "con")) return true;
  else if (!is_regular_file(filename)) return true;
  return false;
}

// Поиск пути к файлу для ввода данных из него
// На входе filename - путь к фалйу, объявлять его надо естественно перед вызовом этой функции
void InputDataFromFile(string& filename) {
  cout << "Введите путь к файлу: " << endl;
  getline(cin, filename); 
  ifstream file(filename, ios_base::binary);
  bool Values = false;
  while (!file || Filenamecheck(filename)) {//Проверяет существование файла по указанному пути
    file.close();
    cerr << "Такого файла не существует" << endl;
    cout << "Введите путь к файлу: " << endl;
    getline(cin, filename);
    file.open(filename);
  }
  // Здесь надо сделать проверку на адекавтность данных в файле 
  // например...
  /*bool Values = false;
  while (!Values) {
    while (!file || Filenamecheck(filename)) {//Проверяет существование файла по указанному пути
      file.close();
      cerr << "Такого файла не существует" << endl;
      cout << "Введите путь к файлу: " << endl;
      getline(cin, filename);
      file.open(filename);
    }
    size_t count = 0; //счетчик количества данных в данном файле
    int temp; // Переменная в которую мы временно будем вкладывать символ из файла
    size_t firstin = 0;
    size_t twoin = 0;
    while (file) { //Проверяем корректность данных в файле
      if (count != 0) file >> temp; // вводим в переменную temp данные из файла
      else {
        file >> firstin;
        file >> twoin;
      }
      if (file.fail() && !file.eof()) { 
        count = 0; // Найдены неккоректные символы
        file.close();
        cerr << "В файле найдены некорректные данные" << endl;
        cout << "Введите путь к файлу: " << endl;
        getline(cin, filename);
        file.open(filename);
        continue;
      }
      count++;
      if (file.eof() && count == firstin * twoin + 1) { 
        file.close();
        file.open(filename);
        Values = true; // Выходим из цикла и в дальнейшим работаем с данным файлом
        break;
      }
      if (file.eof() && count != firstin * twoin + 1){ // Если количество данных подошло к концу и оно не равно нужному
        file.close();
        count = 0;
        cerr << "Количество данных не соответствует условию." << endl;
        cout << "Введите путь к файлу: " << endl;
        getline(cin, filename);
        file.open(filename);
      }
    }
  }*/
}
//Далее надо в модуле, в котором ты реализуешь фугкцию
//для работы проги из файла ипользовать полученный путь,
//чтобы вывести из него данные

// Проверка на атрибуты файла, если файл который вы хотите использовать 
// м.б. открыт только в режиме чтения возвращает false, иначе true
bool AttributeFile(string filename) {
  WIN32_FIND_DATAA findData;
  LPCSTR name = filename.c_str();
  FindFirstFileA(name, &findData);
  if (findData.dwFileAttributes & FILE_ATTRIBUTE_READONLY) {
    cout << "Данный файл имеет атрибут \"только для чтения\"." << endl;
    return false;
  }
  else return true;
}


// Поиск пути для сохранения работы программы 
void SaveTheDataAndСhecking(string& filename){
  cout << "Введите путь к файлу: " << endl;
  getline(cin, filename);
  ifstream file(filename, ios_base::binary);
  while (Filenamecheck(filename) || !AttributeFile(filename)) {
    file.close();
    cout << "Вы ввели недопустимый путь к файлу" << endl;
    cout << "Введи путь к файлу снова" << endl;
    getline(cin, filename);
    file.open(filename);
  }
  file.close();
  while (file) {
    cout << "Такой файл уже существует" << endl;
    cout << "Нажмите 0, чтобы перезаписать его" << endl;
    cout << "Нажмите 1, чтобы ввести новый путь к файлу" << endl;
    double var = Foolproof<double>();
    if (var == OVERWRITE) {
      file.open(filename);
      break;
    }
    else if (var == NEW) {
      file.close();
      cout << "Введите путь к файлу: " << endl;
      getline(cin, filename);
      file.open(filename);
      while (Filenamecheck(filename) || !AttributeFile(filename)) {
        file.close();
        cout << "Вы ввели недопустимое имя" << endl;
        cout << "Введи путь к файлу снова" << endl;
        getline(cin, filename);
        file.open(filename);
      }
    }
  }
  file.close();
  return;
}

//Далее надо в модуле, в котором ты реализуешь функцию
//для сохранения работы проги ипользовать полученный путь,
//чтобы ввести данные в файл