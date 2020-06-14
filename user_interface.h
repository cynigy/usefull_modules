// Автор: Тюлькина И.П.
// Пользовательский интерфейс
#pragma once

enum Variant {
  PROGRAM_EXIT,
  DESCRIPTION,
  ENTER_DATA,
  WORK_WITH_FILES, 
  VIEW_THE_TESTS,
};
enum WorkText {
  INSERT = 1,
  INSERT_FROM_FILE,
  NUMBER_SIMB,
  SAVE_FILE,
};
//Защита от дурака
template <typename T>
T Foolproof();
//Ввод варианта из меню
int UsersMenuInputVariants();
//Защита от дурака для ввода из меню
int FoolproofForUserMenu();
int MenuInputP();
//возврат в меню
int AgainToTheMenu();
