// �����: �������� �.�.
// ���������������� ���������
#include <iostream> 
#include "user_interface.h"

using namespace std;

// ������ �� ������
// ���������� ����������� ��������� ����� � ����������

template <typename T>
T Foolproof() {
  while (true) {
    T a;
    cin >> a;
    if (cin.fail()) { // ���� ���������� ���������� ��������� ���������,
      cin.clear();  // �� ���������� cin � '�������' ����� ������
      cin.ignore(INT_MAX, '\n'); // � ������� �������� ����������� ����� �� �������� ������
      cout << "�� ����������� ����� ��������� ��������. ����������, ����������� ������ ��� �����.\n";
      continue;
    }
    cin.ignore(INT_MAX, '\n'); // ������� ������ ��������

    if (cin.gcount() > 1) {// ���� �� �������� ����� ������ �������
      cout << "�� ����������� ����� ��������� ��������. ����������, ����������� ������ ��� �����.\n";
      continue; // �� ���� ���� ��������� ������������ 
    }
    else {
      return a;
    }
  }
}

// ������ �� ������ ��� ����������������� ����
// ���������� ����� 1, 2, 3, 4, 0
int FoolproofForUserMenu() {
  int a = Foolproof<int>();
  while (a != PROGRAM_EXIT && a != DESCRIPTION && a != ENTER_DATA && a != VIEW_THE_TESTS 
    && a != WORK_WITH_FILES) {
      cout << "����������, ������� ���� �� ������������ ��������" << endl;
      cout << ">>> ";
      a = Foolproof<int>();
  }
  return a;
}

// ��������� ���� ������������, ���������� ����� ������������ (����� �����)
int UsersMenuInputVariants() {
  int variant;
  cout << "������� ����� \n";
  cout << "1 ����� ����������� �������� ���������\n"
    << "2 ����� ������ ����� � ���������� \n"
    << "3 ����� ������ ����� �� �����\n"
    << "4 ����� �������������� ���������\n"
    << "0 ����� ����� �� ���������\n" << endl;
  cout << ">>> ";

  variant = FoolproofForUserMenu();

  return variant;
}

int FoolproofForP() {
  int a = Foolproof<int>();
  while (a != PROGRAM_EXIT && a != INSERT && a != INSERT_FROM_FILE && a != NUMBER_SIMB
    && a != SAVE_FILE) {
    cout << "����������, ������� ���� �� ������������ ��������" << endl;
    cout << ">>> ";
    a = Foolproof<int>();
  }
  return a;
}

int MenuInputP() {
  int variant;
  cout << "������� ����� \n";
  cout << "1 ����� �������� ������������������ �������� � ������ ������\n"
    << "2 ����� �������� ����� �� �����\n"
    << "3 ����� ��������� ���������� ��������, ����, ������� � ������\n"
    << "4 ����� ��������� ����� � ����" << endl
    << "0 ����� ����� � ����� ����" << endl;
  cout << ">>> ";
  variant = FoolproofForP();
  return variant;
}

int AgainToTheMenu() {
  cout << "������� 0, ����� �����\n"
    << "������� ����� ����� ����� 0, ����� ������� � ����" << endl;
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
