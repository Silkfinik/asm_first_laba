#include <iostream>

int main() {
	int n, k, sum = -1; // �������������� sum = -1, ����� � ������ ������� �� 0 ������� ���������
	std::cout << "\tSum of digits of the natural number N divisible by K\n" << std::endl;
	std::cout << "Enter N: ";
	std::cin >> n;
	std::cout << "Enter K: ";
	std::cin >> k;
	_asm {
		mov ebx, k // ���������� k � ebx
		cmp ebx, 0 // ���������� ebx � 0
		je loop_end // ���� ebx = 0, �� ����������� ���� (�� ���� �� ������� xD )
		mov sum, 0 // �������������� sum = 0
		loop_start: // ������ �����
			mov ecx, 10 // ���������� 10 � ecx
			mov eax, n // ���������� n � eax
			cmp eax, 0 // ���������� eax � 0
			je loop_end // ���� eax = 0, �� ��������� � loop_end
			mov edx, 0 // �������� edx
			div ecx // ����� eax �� ecx, ��������� � eax, ������� � edx
			mov n, eax // ��������� ��������� ������� � n
			mov ecx, edx // ��������� ������� �� ������� � ecx (��������� ����� �����)
			mov edx, 0 // �������� edx
			mov eax, ecx // �������� ecx (��������� ����� �����) � eax
			div ebx // ����� eax (��������� ����� �����) �� ebx, ��������� � eax, ������� � edx
			mov eax, ecx // ���������� eax �� ecx (��������� ����� �����)
			cmp edx, 0 // ���������� edx (������� �� �������) � 0
			je sum_add // ���� ������� ����� 0 ��������� � ����� sum_add
			jmp loop_start // ����� ��������� � ������ �����
		sum_add: // ����� sum_add
			add sum, eax // ���������� � sum �������� eax (��������� ����� �����)
			jmp loop_start // ��������� � ������ �����
		loop_end: // ����� �����
	}
	if (sum == -1) {
		std::cout << "Divide by 0!";
	}
	else {
		std::cout << "Sum: " << sum;
	}
}