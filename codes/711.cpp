// ; ����һ��Ԫ�ز�����20���������� numbers ���������Ѱ��ǵݼ�˳�����У�������������ҳ��������֮�͵���Ŀ���� target ����������
// ; ��������������ֱ��� numbers[index1] �� numbers[index2] ���� 1 <= index1 < index2 <= numbers.length ��
// �Գ���Ϊ 2 ���������� [index1, index2] ����ʽ�����������������±� index1 �� index2��
// ; �Ӽ�����������Ԫ�ظ���������Ԫ���Լ�Ŀ���������ÿո�ֿ���
// ; �������Ҫ��������������±� index1 �� index2������á�,���ֿ�
// ; ���û�з���Ҫ��Ľ���������No solution found.

#include <stdio.h>

int main() {
    int size;
    int target;
    int numbers[20];
    int index1, index2;
    index1 = -1;

    scanf("%d", &size);
    for (int i=0; i<size; i++) { scanf("%d", numbers+i); }
    scanf("%d", &target);

    for (int i=0; i<size; i++) {
        for (int j=i+1; j<size;j++) {
            if ( numbers[i]+numbers[j] == target ) {
                index1 = i+1;
                index2 = j+1;
                goto outside;
            }
        }
    }

    outside:
    if (index1 == -1) { printf("No solution found.\n");}
    else { printf("%d,%d\n", index1, index2); }
}