// �����: �������� ����� �������� 
// ������ � �������
#include <iostream> 
#include <Windows.h>
#include <fstream>
#include <filesystem> 
// ������ ����������������� ���������,
//��� Foolproof() - ������� ��� �������� ����������������� �����
#include "user_interface.h" 
#include <string>

using namespace std::filesystem;
using namespace std;

enum Files {
  OVERWRITE,
  NEW,
};

//�������� �� ����������� ������������� �����
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

// ����� ���� � ����� ��� ����� ������ �� ����
// �� ����� filename - ���� � �����, ��������� ��� ���� ����������� ����� ������� ���� �������
void InputDataFromFile(string& filename) {
  cout << "������� ���� � �����: " << endl;
  getline(cin, filename); 
  ifstream file(filename, ios_base::binary);
  bool Values = false;
  while (!file || Filenamecheck(filename)) {//��������� ������������� ����� �� ���������� ����
    file.close();
    cerr << "������ ����� �� ����������" << endl;
    cout << "������� ���� � �����: " << endl;
    getline(cin, filename);
    file.open(filename);
  }
  // ����� ���� ������� �������� �� ������������ ������ � ����� 
  // ��������...
  /*bool Values = false;
  while (!Values) {
    while (!file || Filenamecheck(filename)) {//��������� ������������� ����� �� ���������� ����
      file.close();
      cerr << "������ ����� �� ����������" << endl;
      cout << "������� ���� � �����: " << endl;
      getline(cin, filename);
      file.open(filename);
    }
    size_t count = 0; //������� ���������� ������ � ������ �����
    int temp; // ���������� � ������� �� �������� ����� ���������� ������ �� �����
    size_t firstin = 0;
    size_t twoin = 0;
    while (file) { //��������� ������������ ������ � �����
      if (count != 0) file >> temp; // ������ � ���������� temp ������ �� �����
      else {
        file >> firstin;
        file >> twoin;
      }
      if (file.fail() && !file.eof()) { 
        count = 0; // ������� ������������ �������
        file.close();
        cerr << "� ����� ������� ������������ ������" << endl;
        cout << "������� ���� � �����: " << endl;
        getline(cin, filename);
        file.open(filename);
        continue;
      }
      count++;
      if (file.eof() && count == firstin * twoin + 1) { 
        file.close();
        file.open(filename);
        Values = true; // ������� �� ����� � � ���������� �������� � ������ ������
        break;
      }
      if (file.eof() && count != firstin * twoin + 1){ // ���� ���������� ������ ������� � ����� � ��� �� ����� �������
        file.close();
        count = 0;
        cerr << "���������� ������ �� ������������� �������." << endl;
        cout << "������� ���� � �����: " << endl;
        getline(cin, filename);
        file.open(filename);
      }
    }
  }*/
}
//����� ���� � ������, � ������� �� ���������� �������
//��� ������ ����� �� ����� ����������� ���������� ����,
//����� ������� �� ���� ������

// �������� �� �������� �����, ���� ���� ������� �� ������ ������������ 
// �.�. ������ ������ � ������ ������ ���������� false, ����� true
bool AttributeFile(string filename) {
  WIN32_FIND_DATAA findData;
  LPCSTR name = filename.c_str();
  FindFirstFileA(name, &findData);
  if (findData.dwFileAttributes & FILE_ATTRIBUTE_READONLY) {
    cout << "������ ���� ����� ������� \"������ ��� ������\"." << endl;
    return false;
  }
  else return true;
}


// ����� ���� ��� ���������� ������ ��������� 
void SaveTheDataAnd�hecking(string& filename){
  cout << "������� ���� � �����: " << endl;
  getline(cin, filename);
  ifstream file(filename, ios_base::binary);
  while (Filenamecheck(filename) || !AttributeFile(filename)) {
    file.close();
    cout << "�� ����� ������������ ���� � �����" << endl;
    cout << "����� ���� � ����� �����" << endl;
    getline(cin, filename);
    file.open(filename);
  }
  file.close();
  while (file) {
    cout << "����� ���� ��� ����������" << endl;
    cout << "������� 0, ����� ������������ ���" << endl;
    cout << "������� 1, ����� ������ ����� ���� � �����" << endl;
    double var = Foolproof<double>();
    if (var == OVERWRITE) {
      file.open(filename);
      break;
    }
    else if (var == NEW) {
      file.close();
      cout << "������� ���� � �����: " << endl;
      getline(cin, filename);
      file.open(filename);
      while (Filenamecheck(filename) || !AttributeFile(filename)) {
        file.close();
        cout << "�� ����� ������������ ���" << endl;
        cout << "����� ���� � ����� �����" << endl;
        getline(cin, filename);
        file.open(filename);
      }
    }
  }
  file.close();
  return;
}

//����� ���� � ������, � ������� �� ���������� �������
//��� ���������� ������ ����� ����������� ���������� ����,
//����� ������ ������ � ����