#include "../TimeCheck/TimeCheck.h"
#define MAX_COUNT 1<<10
size_t counter = 0;

void testSwitch()
{
    size_t i;
    for (i = 0; i < MAX_COUNT; i++)
    {
        const size_t c = rand() % 20 + 1;

        switch (c)
        {
        case 1: counter += 20; break;
        case 2: counter += 33; break;
        case 3: counter += 62; break;
        case 4: counter += 15; break;
        case 5: counter += 416; break;
        case 6: counter += 3545; break;
        case 7: counter += 23; break;
        case 8: counter += 81; break;
        case 9: counter += 256; break;
        case 10: counter += 15865; break;
        case 11: counter += 3234; break;
        case 12: counter += 22345; break;
        case 13: counter += 1242; break;
        case 14: counter += 12341; break;
        case 15: counter += 41; break;
        case 16: counter += 34321; break;
        case 17: counter += 232; break;
        case 18: counter += 144231; break;
        case 19: counter += 32; break;
        case 20: counter += 1231; break;
        }
    }
}

void testSwitch2()
{
    size_t i;
    for (i = 0; i < MAX_COUNT; i++)
    {
        const size_t c = rand() % 20 + 1;
        // ���ο��� jump�ؾ��ϴ� �޸� �ּҰ��� ���
        // �ش� �޸� �ּҷ� jump

        switch (c)
        {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5: 
        case 6: counter += 1;
        case 7:
        case 8:
        case 9: 
        case 10: 
        case 11: 
        case 12: counter += 2;
        case 13: 
        case 14: 
        case 15:
        case 16: counter = counter + 1;
        case 17: 
        case 18:
        case 19:
        case 20: counter += 1231; break;
        }
    }
}

void testSwitch3()
{
    size_t i;
    for (i = 0; i < MAX_COUNT; i++)
    {
        const size_t c = rand() % 20 + 1;
        switch (0)
        {
            case 0:
            counter += 1231;
        }
    }
}

void testIf()
{
    size_t i;
    for (i = 0; i < MAX_COUNT; i++)
    {
        const size_t c = rand() % 20 + 1;
        if (c == 1) { counter += 20; }
        else if (c == 2) { counter += 33; }
        else if (c == 3) { counter += 62; }
        else if (c == 4) { counter += 15; }
        else if (c == 5) { counter += 416; }
        else if (c == 6) { counter += 3545; }
        else if (c == 7) { counter += 23; }
        else if (c == 8) { counter += 81; }
        else if (c == 9) { counter += 256; }
        else if (c == 10) { counter += 15865; }
        else if (c == 11) { counter += 3234; }
        else if (c == 12) { counter += 22345; }
        else if (c == 13) { counter += 1242; }
        else if (c == 14) { counter += 12341; }
        else if (c == 15) { counter += 41; }
        else if (c == 16) { counter += 34321; }
        else if (c == 17) { counter += 232; }
        else if (c == 18) { counter += 144231; }
        else if (c == 19) { counter += 32; }
        else if (c == 20) { counter += 1231; }
    }
}


void testIf2()
{
    size_t i;
    for (i = 0; i < MAX_COUNT; i++)
    {
        const size_t c = rand() % 20 + 1;
        // ���������
        // c�� ���� 1 �� jump
        // c�� ���� 2 �� jump
        // c�� ���� 3 �� jump
        // c�� ���� 4 �� jump
        // c�� ���� 5 �� jump
        // c�� ���� 6 �� jump
        // c�� ���� 7 �� jump
        // c�� ���� 8 �� jump
        // c�� ���� 9 �� jump
        // ...
        if (c == 1 ||
        c == 2 ||
        c == 3 ||
        c == 4 ||
        c == 5 ||
        c == 6 ||
        c == 7 ||
        c == 8 ||
        c == 9 ||
        c == 10 ||
        c == 11 ||
        c == 12 ||
        c == 13 ||
        c == 14 ||
        c == 15 ||
        c == 16 ||
        c == 17 ||
        c == 18 ||
        c == 19 ||
        c == 20) { counter += 1231; }
    }
}


// if�� switch�� ����
// if�� ���� �ϳ��� ���ؼ� jump���θ� ���� 
// switch�� jump�� �޸� �ּҸ� ����ؼ� jump
// if���� ª���� -> if���� �� ���Ǿ� �� �ð� < jump�� �޸� �ּ� ��� �� jump�ϴ� �ð�
// if���� ��� -> if���� �� ���Ǿ� �� �ð��� ����� > switch���� jump �޸� �ּ� ���ð� ����

int main()
{
    TIME_UNIT ATime = CheckFunctionTime([]()
        {
            testSwitch();
        });

    TIME_UNIT BTime = CheckFunctionTime([]()
        {
            testIf();
        });

    TIME_UNIT CTime = CheckFunctionTime([]()
        {
            testSwitch2();
        });

    TIME_UNIT DTime = CheckFunctionTime([]()
        {
            testIf2();
        });

    TIME_UNIT ETime = CheckFunctionTime([]()
        {
            testSwitch3();
        });
	return 0;
}