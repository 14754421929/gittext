#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

typedef struct {
    char date[20];
    double amount;
    char category[20];
    char note[50];
} BillRecord;

BillRecord records[MAX_RECORDS];
int recordCount = 0;

void recordIncome();
void recordExpense();
void displayRecords();
double calculateTotalIncome();
double calculateTotalExpense();

int main() {
    int choice;
    do {
        printf("\n�����˵�����ϵͳ\n");
        printf("1. ��¼����\n");
        printf("2. ��¼֧��\n");
        printf("3. ��ʾ��¼\n");
        printf("4. ����������\n");
        printf("5. ������֧��\n");
        printf("0. �˳�\n");
        printf("���������ѡ�� ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                recordIncome();
                break;
            case 2:
                recordExpense();
                break;
            case 3:
                displayRecords();
                break;
            case 4:
                printf("�����룺%.2f\n", calculateTotalIncome());
                break;
            case 5:
                printf("��֧����%.2f\n", calculateTotalExpense());
                break;
            case 0:
                printf("�����˳�...\n");
                break;
            default:
                printf("��Чѡ�������ԡ�\n");
        }
    } while (choice!= 0);

    return 0;
}

void recordIncome() {
    if (recordCount == MAX_RECORDS) {
        printf("�Ѵﵽ����¼����\n");
        return;
    }
    BillRecord record;
    printf("�������ڣ� ");
    scanf("%s", record.date);
    printf("���������Ϊ�������� ");
    scanf("%lf", &record.amount);
    if (record.amount <= 0) {
        printf("�����Ч���������Ϊ������\n");
        return;
    }
    printf("������� ");
    scanf("%s", record.category);
    printf("���뱸ע�� ");
    scanf("%s", record.note);
    records[recordCount++] = record;
}

void recordExpense() {
    if (recordCount == MAX_RECORDS) {
        printf("�Ѵﵽ����¼����\n");
        return;
    }
    BillRecord record;
    printf("�������ڣ� ");
    scanf("%s", record.date);
    printf("���������Ϊ�������� ");
    scanf("%lf", &record.amount);
    if (record.amount <= 0) {
        printf("�����Ч��֧������Ϊ������\n");
        return;
    }
    printf("������� ");
    scanf("%s", record.category);
    printf("���뱸ע�� ");
    scanf("%s", record.note);
    records[recordCount++] = record;
}

void displayRecords() {
    printf("\n�˵���¼��\n");
    for (int i = 0; i < recordCount; i++) {
        printf("���ڣ�%s����%.2f�����%s����ע��%s\n", records[i].date, records[i].amount, records[i].category, records[i].note);
    }
}

double calculateTotalIncome() {
    double totalIncome = 0;
    for (int i = 0; i < recordCount; i++) {
        if (records[i].amount > 0) {
            totalIncome += records[i].amount;
        }
    }
    return totalIncome;
}

double calculateTotalExpense() {
    double totalExpense = 0;
    for (int i = 0; i < recordCount; i++) {
        if (records[i].amount < 0) {
            totalExpense += records[i].amount;
        }
    }
    return totalExpense;
}
