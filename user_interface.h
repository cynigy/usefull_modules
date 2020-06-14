// �����: �������� �.�.
// ���������������� ���������
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
//������ �� ������
template <typename T>
T Foolproof();
//���� �������� �� ����
int UsersMenuInputVariants();
//������ �� ������ ��� ����� �� ����
int FoolproofForUserMenu();
int MenuInputP();
//������� � ����
int AgainToTheMenu();
