// Автор: Тюлькина И.П.
// Пользовательскиц интерфейс
#include <iostream> 
#include "user_interface.h"

using namespace std;

// защита от дурака
// возвращает проверенный результат ввода с клавиатуры

template <typename T>
T Foolproof() {
  while (true) {
    T a;
    cin >> a;
    if (cin.fail()) { // если предыдущее извлечение оказалось неудачным,
      cin.clear();  // то возвращаем cin в 'обычный' режим работы
      cin.ignore(INT_MAX, '\n'); // и удаляем значения предыдущего ввода из входного буфера
      cout << "Вы неправильно ввели последнее значение. Пожалуйста, попытайтесь ввести его снова.\n";
      continue;
    }
    cin.ignore(INT_MAX, '\n'); // удаляем лишние значения

    if (cin.gcount() > 1) {// если мы очистили более одного символа
      cout << "Вы неправильно ввели последнее значение. Пожалуйста, попытайтесь ввести его снова.\n";
      continue; // то этот ввод считается некорректным 
    }
    else {
      return a;
    }
  }
}

// защита от дурака для пользовательского меню
// возвращает числа 1, 2, 3, 4, 0
int FoolproofForUserMenu() {
  int a = Foolproof<int>();
  while (a != PROGRAM_EXIT && a != DESCRIPTION && a != ENTER_DATA && a != VIEW_THE_TESTS 
    && a != WORK_WITH_FILES) {
      cout << "Пожалуйста, введите одно из предложенных значений" << endl;
      cout << ">>> ";
      a = Foolproof<int>();
  }
  return a;
}

// Считывает ввод пользователя, возвращает выбор пользователя (целое число)
int UsersMenuInputVariants() {
  int variant;
  cout << "Введите цифру \n";
  cout << "1 Чтобы просмотреть описание программы\n"
    << "2 Чтобы ввести текст с клавиатуры \n"
    << "3 Чтобы ввести текст из файла\n"
    << "4 Чтобы протестировать программу\n"
    << "0 Чтобы выйти из программы\n" << endl;
  cout << ">>> ";

  variant = FoolproofForUserMenu();

  return variant;
}

int FoolproofForP() {
  int a = Foolproof<int>();
  while (a != PROGRAM_EXIT && a != INSERT && a != INSERT_FROM_FILE && a != NUMBER_SIMB
    && a != SAVE_FILE) {
    cout << "Пожалуйста, введите одно из предложенных значений" << endl;
    cout << ">>> ";
    a = Foolproof<int>();
  }
  return a;
}

int MenuInputP() {
  int variant;
  cout << "Введите цифру \n";
  cout << "1 Чтобы вставить последовательность символов в начало строки\n"
    << "2 Чтобы вставить текст из файла\n"
    << "3 Чтобы посчитать количество символов, слов, абзацев в тексте\n"
    << "4 Чтобы сохранить текст в файл" << endl
    << "0 Чтобы выйти в общее меню" << endl;
  cout << ">>> ";
  variant = FoolproofForP();
  return variant;
}

int AgainToTheMenu() {
  cout << "Нажмите 0, чтобы выйти\n"
    << "Нажмите любую цифру кроме 0, чтобы попасть в меню" << endl;
  double a = Foolproof<double>();
  int var;
  if (a != PROGRAM_EXIT) {
    var = UsersMenuInputVariants();
  }
  else {
    var = PROGRAM_EXIT;
  }
  return var;
}
