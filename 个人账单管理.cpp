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
        printf("\n个人账单管理系统\n");
        printf("1. 记录收入\n");
        printf("2. 记录支出\n");
        printf("3. 显示记录\n");
        printf("4. 计算总收入\n");
        printf("5. 计算总支出\n");
        printf("0. 退出\n");
        printf("请输入你的选择： ");
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
                printf("总收入：%.2f\n", calculateTotalIncome());
                break;
            case 5:
                printf("总支出：%.2f\n", calculateTotalExpense());
                break;
            case 0:
                printf("正在退出...\n");
                break;
            default:
                printf("无效选择。请重试。\n");
        }
    } while (choice!= 0);

    return 0;
}

void recordIncome() {
    if (recordCount == MAX_RECORDS) {
        printf("已达到最大记录数。\n");
        return;
    }
    BillRecord record;
    printf("输入日期： ");
    scanf("%s", record.date);
    printf("输入金额（必须为正数）： ");
    scanf("%lf", &record.amount);
    if (record.amount <= 0) {
        printf("金额无效。收入必须为正数。\n");
        return;
    }
    printf("输入类别： ");
    scanf("%s", record.category);
    printf("输入备注： ");
    scanf("%s", record.note);
    records[recordCount++] = record;
}

void recordExpense() {
    if (recordCount == MAX_RECORDS) {
        printf("已达到最大记录数。\n");
        return;
    }
    BillRecord record;
    printf("输入日期： ");
    scanf("%s", record.date);
    printf("输入金额（必须为正数）： ");
    scanf("%lf", &record.amount);
    if (record.amount <= 0) {
        printf("金额无效。支出必须为正数。\n");
        return;
    }
    printf("输入类别： ");
    scanf("%s", record.category);
    printf("输入备注： ");
    scanf("%s", record.note);
    records[recordCount++] = record;
}

void displayRecords() {
    printf("\n账单记录：\n");
    for (int i = 0; i < recordCount; i++) {
        printf("日期：%s，金额：%.2f，类别：%s，备注：%s\n", records[i].date, records[i].amount, records[i].category, records[i].note);
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
