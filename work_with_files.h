#pragma once
// ����� �������� �.�.
// ������ � �������

enum Files {
  OVERWRITE, 
  NEW,
  ARR,
};

//����� ����� ��� ����� �������� ������
void InputDataFromFile(std::string& filename);

//����� ����� ��� ���������� ������ � ����
void SaveTheDataAnd�hecking(std::string& filename);
