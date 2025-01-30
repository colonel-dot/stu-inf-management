#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct stu {
    char name[20];
    char number[20];
    int math;
    int clag;
    int sum;
    double ave;
    char account[20];
    char password[20];
    char find_Password[20];
    struct stu* front;
    struct stu* next;
}stu;
typedef struct te_account {
    char name[20];
    char account[20];
    char password[20];
    char find_Psd[20];
    struct te_account* next;
}tact;
void Free_List(stu** head) {
    stu* temp = *head;
    stu* last = NULL;
    while (temp) {
        last = temp->next;
        free(temp);
        temp = last;
    }
}
void new_File_Input(FILE* fp, int flag) {//输入待注册账号到文件中
    /*char wait1[50] = "待办事项1.学生注册账号\n";
    char wait2[50] = "待办事项1.教师注册账号\n";*/
    system("cls");
    printf("账号注册界面：\n");
    int len1 = 0, len2 = 0, len3 = 0;
    char name[20] = { 0 }, number[20] = { 0 }, account[20] = { 0 }, password[20] = { 0 }, refind[10] = { 0 };
    if (flag == 1)
    {
        printf("请依次输入注册学生的姓名，学号，五位注册账号，密码（至少6位）：\n");
        scanf("%19s %19s %19s %19s", name, number, account, password);
        len1 = strlen(account), len2 = strlen(password);
        printf("输入身份证号后六位和一位随机数字作为密保问题以供密码找回：");
        scanf("%9s", refind);
        len3 = strlen(refind);
        while (len1 != 5 || len2 < 6 || len3 != 7) {
            printf("输入不合法，请重新输入");
            printf("请依次输入注册学生的姓名，学号，五位注册账号，密码（至少6位）：\n");
            scanf("%19s %19s %19s %19s", name, number, account, password);
            len1 = strlen(account), len2 = strlen(password);
            printf("输入身份证号后六位和一位随机数字作为密保问题以供密码找回：");
            scanf("%9s", refind);
            len3 = strlen(refind);
        }
        fprintf(fp, "%s %s %s %s %s", name, number, account, password, refind);
    }
    else
    {
        printf("请依次输入注册教师的姓名，五位注册账号，密码(至少六位)：\n");
        scanf("%18s %18s %18s", name, account, password);
        printf("输入身份证号后六位和一位随机数字作为密保问题以供密码找回：");
        //fprintf(fp, "%s", wait2);
        scanf("%9s", refind);
        printf("\n");
        len1 = strlen(account), len2 = strlen(password), len3 = strlen(refind);
        while (len1 != 5 || len2 < 6 || len3 != 7) {
            printf("输入不合法，请重新输入");
            printf("请依次输入注册教师的姓名，账号，密码(至少六位)：\n");
            scanf("%18s %18s %18s", name, account, password);
            printf("输入身份证号后六位和一位随机数字作为密保问题以供密码找回：");
            //fprintf(fp, "%s", wait2);
            scanf("%9s", refind);
            printf("\n");
            len1 = strlen(account), len2 = strlen(password), len3 = strlen(refind);
        }
        fprintf(fp, "%s %s %s %s", name, account, password, refind);
    }
}
void account_Register() {
    char t;
    int flag = 0, temp = 0;
    system("cls");
    printf("选择1.学生注册 2.教师注册：\n");
    scanf("%d", &flag);
    FILE* fps1 = fopen("C:\\Users\\30371\\Desktop\\待办1学生.txt", "a");
    FILE* fps2 = fopen("C:\\Users\\30371\\Desktop\\待办1教师.txt", "a");
    while (1) {
        switch (flag) {
        case 1:new_File_Input(fps1, flag);
            temp = 1;
            fclose(fps1);
            fclose(fps2);
            break;
        case 2:new_File_Input(fps2, flag);
            temp = 1;
            fclose(fps1);
            fclose(fps2);
            break;
        default:printf("违规输入，请重新输入：");
        }
        if (temp) {
            break;
        }
    }
    printf("注册请求已发送至管理员端，等待管理员同意\n");
    printf("输入任意字符返回上一层");
    scanf(" %c", &t);
    return;
}
void te_St_Out(char* name, char* number, int math, int clag, char* act, char* password, char* Find_psd, FILE* fp) {//输出数据到文件中
    double ave = (math + clag) / 2;
    int sum = math + clag;
    //char name1[20] = "学生姓名\t", number1[20] = "学生学号\t", math1[20] = "高数成绩\t", clag1[20] = "C语言成绩\t", sum1[20] = "总分\t", ave1[20] = "平均分\t";
    /*fwrite(name, sizeof(char), strlen(name), fp);
    fwrite(number, sizeof(char), strlen(number), fp);
    fwrite(&math, sizeof(int), 1, fp);
    fwrite(&clag, sizeof(int), 1, fp);
    fwrite(&ave, sizeof(double), 1, fp);*/
    fprintf(fp, "%s\t%s\t%d\t%d\t%d\t%.2lf\t%s\t%s\t%s\n", name, number, math, clag, sum, ave, act, password, Find_psd);
}
void Stu_List(stu** head) {
    stu* last = NULL, * p = NULL;
    FILE* fp = fopen("C:\\Users\\30371\\Desktop\\student.txt", "a");
    system("cls");
    printf("请依次输入你要增加的学生的姓名，学号，高数成绩，C语言成绩：（按0或9返回上一步）\n");
    //char name1[20] = "学生姓名\t", number1[20] = "学生学号\t", math1[20] = "高数成绩\t", clag1[20] = "C语言成绩\t", sum1[20] = "总分\t", ave1[20] = "平均分\t";
    //fprintf(fp, "%s %s %s %s %s %s\n", name1, number1, math1, clag1, sum1, clag1);
    while (1) {
        p = (stu*)malloc(sizeof(stu));
        scanf("%19s", p->name);
        if (!strcmp(p->name, "9") || !strcmp(p->name, "0")) return;
        scanf("%19s %d %d", p->number, &p->math, &p->clag);
        p->ave = 1.0 * (p->math + p->clag) / 2;
        p->sum = p->math + p->clag;
        p->next = NULL;
        p->front = NULL;
        char name[20] = { 0 }, number[20] = { 0 }, act[20] = { 0 }, password[20] = { 0 }, Find_psd[20] = { 0 };
        strcpy(name, p->name);
        strcpy(number, p->number);
        int math = p->math, clag = p->clag, sum = p->math + p->clag;
        double ave = p->ave;
        strcpy(password, "0");
        strcpy(act, "0");
        strcpy(Find_psd, "0");
        te_St_Out(name, number, math, clag, act, password, Find_psd, fp);
        if (*head) {
            last = *head;
            while (last->next) {
                last = last->next;
            }
            last->next = p;
            p->front = last;
        }
        else {
            *head = p;
        }
    }
    fclose(fp);
}
void new_Link_File(stu** head, FILE* fps) {//从文件中读取数据到链表中
    stu* p = *head, * last = NULL;
    char name[20] = { 0 }, number[20] = { 0 }, act[20] = { 0 }, psd[20] = { 0 }, psd_Find[10] = { 0 };
    strcpy(act, "0");
    strcpy(psd_Find, "0");
    strcpy(psd, "0");
    int math, clag, sum;
    double ave;
    while (fscanf(fps, "%s %s %d %d %d %lf %s %s %s\n", name, number, &math, &clag, &sum, &ave, act, psd, psd_Find) != EOF) {
        p = (stu*)malloc(sizeof(stu));
        strcpy(p->name, name);
        strcpy(p->number, number);
        strcpy(p->account, act);
        strcpy(p->password, psd);
        strcpy(p->find_Password, psd_Find);
        p->math = math, p->clag = clag, p->ave = ave, p->sum = sum;
        p->next = NULL;
        p->front = NULL;
        if (*head) {
            last = *head;
            while (last->next) {
                last = last->next;
            }
            last->next = p;
            p->front = last;
        }
        else {
            *head = p;
        }
    }
    fclose(fps);
}
void Delete_stu() {
    int flag = 0;
    stu* head = NULL, * last = NULL, * p = NULL;
    char temp[20], Find_psd[20] = { 0 };
    FILE* fps = fopen("C:\\Users\\30371\\Desktop\\student.txt", "r");
    new_Link_File(&head, fps);
    while (1) {
        system("cls");
        if (flag == 1) {
            printf("删除成功\n");
            flag = 0;
        }
        else if (flag == 2) {
            printf("系统中没有这位学生名字，请重新输入：\n");
            flag = 0;
        }
        printf("输入要删除学生的姓名或学号（按0或9返回）:\n");
        scanf("%19s", temp);
        if (!strcmp(temp, "9") || !strcmp(temp, "0")) break;
        if (head == NULL) {
            printf("学生信息系统为空，请先添加学生信息");
        }
        last = head;
        while (strcmp(last->name, temp) != 0 && strcmp(last->number, temp) != 0 && last) {
            p = last;
            last = last->next;
        }
        if (last == NULL || ((!strcmp(head->name, temp) && !strcmp(head->number, temp)))) {
            flag = 2;
            continue;
        }
        if (last == head) {
            head = last->next;
            free(last);
            last = NULL;
            flag = 1;
        }
        else {
            p->next = last->next;
            free(last);
            last = NULL;
            flag = 1;
        }
    }
    last = head;
    FILE* fp = fopen("C:\\Users\\30371\\Desktop\\student.txt", "w");
    fclose(fp);
    while (last) {
        FILE* fpr = fopen("C:\\Users\\30371\\Desktop\\student.txt", "a");
        te_St_Out(last->name, last->number, last->math, last->clag, last->account, last->password, Find_psd, fpr);
        last = last->next;
    }
    Free_List(&head);
    return;
}
void revise_Stu() {
    int flag = 0, k = 0;
    stu* head = NULL, * last = NULL;
    char temp[20], Find_psd[20] = { 0 };
    FILE* fps = fopen("C:\\Users\\30371\\Desktop\\student.txt", "r");
    new_Link_File(&head, fps);
    while (1) {
        system("cls");
        if (flag == 1) {
            printf("修改成功\n");
            flag = 0;
        }
        else if (flag == 2) {
            printf("系统中没有这位学生名字，请检查后重新输入：\n");
            flag = 0;
        }
        printf("输入你要修改的学生姓名或学号(按0或9返回)：");
        scanf("%19s", temp);
        if (!strcmp(temp, "9") || !strcmp(temp, "0")) {
            break;
        }
        if (head == NULL) {
            printf("学生信息系统为空，请先添加学生信息");
        }
        last = head;
        while (strcmp(last->name, temp) != 0 && strcmp(last->number, temp) != 0 && last) {
            last = last->next;
        }
        if (last == NULL) {
            flag = 2;
            continue;
        }
        printf("选择你要修改的内容：\n1.姓名\n2.学号\n3.高数成绩\n4.C语言成绩\n");
        scanf("%d", &k);
        int grade = 0;
        switch (k) {
        case 1:printf("输入%s修改后的姓名\n", last->name);
            scanf("%s", temp);
            strcpy(last->name, temp);
            flag = 1;
            break;
        case 2:printf("输入%s修改后的学号:\n", last->name);
            scanf("%s", temp);
            strcpy(last->number, temp);
            flag = 1;
            break;
        case 3:printf("输入%s修改后的高数成绩：\n", last->name);
            scanf("%d", &grade);
            last->math = grade;
            last->ave = 1.0 * (grade + last->clag) / 2;
            last->sum = last->math + last->clag;
            flag = 1;
            break;
        case 4:printf("输入%s修改后的C语言成绩：\n", last->name);
            scanf("%d", &grade);
            last->clag = grade;
            last->sum = last->math + last->clag;
            last->ave = 1.0 * (grade + last->math) / 2;
            flag = 1;
            break;
        }
        last = head;
        FILE* fp = fopen("C:\\Users\\30371\\Desktop\\student.txt", "w");
        while (last) {
            //te_St_Out(last->name, last->number, last->math, last->clag, last->account, last->password, Find_psd, fp);
            fprintf(fp, "%s %s %d %d %d %.2lf %s %s %s\n", last->name, last->number, last->math, last->clag, last->math + last->clag, 1.0 * (last->math + last->clag) / 2, last->account, last->password, last->find_Password);
            last = last->next;
        }
        fclose(fp);
        Free_List(&head);
    }
    return;
}
void quer() {
    system("cls");
    int flag = -1, fr_Next, cnt = 0;
    char temp[20];
    char name[20] = "学生姓名", number[20] = "学生学号", math[20] = "高数成绩", clag[20] = "C语言成绩", sum[20] = "总分", ave[20] = "平均分";
    printf("1.查询单个学生成绩 2.查询本班学生成绩");
    scanf("%d", &flag);
    while (flag != 1 && flag != 2) {
        printf("输入违规，请重新输入");
        scanf("%d", &flag);
    }
    stu* head = NULL;
    stu* last = head;
    FILE* fp = fopen("C:\\Users\\30371\\Desktop\\student.txt", "r");
    new_Link_File(&head, fp);
    system("cls");
    if (flag == 1) {
        printf("输入你要查询的学生姓名：\n");
        scanf("%s", temp);
        while (last && strcmp(last->name, temp)) {
            last = last->next;
        }
        if (!last) {
            printf("没有该名学生信息，请核对后重新输入");
        }
        else {
            printf("%-20s%-20s%-20s%-17s%-18s%-15s\n", name, number, math, clag, sum, ave);
            printf("%-20s%-15s%-15d%-13d%-15d%-20.2lf\n", last->name, last->number, last->math, last->clag, last->sum, last->ave);
        }
    }
    else {
        last = head;
        while (1) {

            printf("1.查询前一页 2.查询后一页(按0返回上一层)");
            scanf("%d", &fr_Next);
            if (!fr_Next) {
                return;
            }
            while (fr_Next != 1 && fr_Next != 2) {
                printf("输入违规，请重新输入");
                scanf("%d", &fr_Next);
            }
            cnt = 0;
            if (fr_Next == 1) {
                if (!(last->front)) {
                    printf("已是第一页");
                    continue;
                }
                printf("%-20s%-20s%-20s%-17s%-18s%-15s\n", name, number, math, clag, sum, ave);
                while (last->front && cnt < 5) {
                    printf("%-20s%-15s%-15d%-13d%-15d%-20.2lf\n", last->name, last->number, last->math, last->clag, last->sum, last->ave);
                    cnt++;
                    last = last->front;
                }
                if (!(last->front) && cnt < 5) {
                    printf("%-20s%-15s%-15d%-13d%-15d%-20.2lf\n", last->name, last->number, last->math, last->clag, last->sum, last->ave);
                }
            }
            else {
                if (!(last->next)) {
                    printf("已是最后一页");
                    continue;
                }
                printf("%-20s%-20s%-20s%-17s%-18s%-15s\n", name, number, math, clag, sum, ave);
                while (last->next && cnt < 5) {
                    printf("%-20s%-15s%-15d%-13d%-15d%-20.2lf\n", last->name, last->number, last->math, last->clag, last->sum, last->ave);
                    cnt++;
                    last = last->next;
                }
                if (!(last->next) && cnt < 5) {
                    printf("%-20s%-15s%-15d%-13d%-15d%-20.2lf\n", last->name, last->number, last->math, last->clag, last->sum, last->ave);
                }
            }
        }
    }
    Free_List(&head);
}
void quer_Self(char* act) {
    int flag = 0;
    stu* head = NULL;
    char name[20] = "学生姓名", number[20] = "学生学号", math[20] = "高数成绩", clag[20] = "C语言成绩", sum[20] = "总分", ave[20] = "平均分";
    FILE* fp = fopen("C:\\Users\\30371\\Desktop\\student.txt", "r");
    new_Link_File(&head, fp);
    stu* last = head;
    while (last && strcmp(last->account, act)) {
        last = last->next;
    }
    system("cls");
    printf("%-20s%-20s%-20s%-17s%-18s%-15s\n", name, number, math, clag, sum, ave);
    printf("%-20s%-15s%-15d%-13d%-15d%-20.2lf\n", last->name, last->number, last->math, last->clag, last->sum, last->ave);
    Free_List(&head);
    printf("输入5返回上一级");
    scanf("%d", &flag);
    if (flag == 5) {
        return;
    }
}
int node_Number(int cnt) {//计算学生有多少人数
    cnt = 0;
    stu* head = NULL;
    FILE* fp = fopen("C:\\Users\\30371\\Desktop\\student.txt", "r");
    new_Link_File(&head, fp);
    stu* last = head;
    while (last) {
        last = last->next;
        cnt++;
    }
    Free_List(&head);
    return cnt;
}
void print_List(stu** head) {
    stu* t = *head;
    char name[20] = "学生姓名", number[20] = "学生学号", math[20] = "高数成绩", clag[20] = "C语言成绩", sum[20] = "总分", ave[20] = "平均分";
    printf("%-20s%-20s%-20s%-17s%-15s%-15s\n", name, number, math, clag, sum, ave);
    while (t) {
        printf("%-20s%-15s%-15d%-13d%-15d%-20.2lf\n", t->name, t->number, t->math, t->clag, t->sum, t->ave);
        t = t->next;
    }
}
void list_Sort() {//链表排序，成绩从高到低
    system("cls");
    stu* head = NULL;
    int cnt = 0;
    cnt = node_Number(cnt);
    if (cnt <= 2) return;
    FILE* fp = fopen("C:\\Users\\30371\\Desktop\\student.txt", "r");
    new_Link_File(&head, fp);
    stu* last = head, * temp = head;
    if (head->sum < head->next->sum) {
        temp = head->next;
        head->next = head->next->next;
        temp->next = head;
        head = temp;
    }
    //for (int i = 0; i < cnt - 1; i++) {
    //    last = head->next;
    //    while (last->next && last) {
    //        if (last->sum < last->next->sum) {
    //            temp->next = last->next;
    //            last->next = last->next->next;
    //            temp->next->next = last;
    //        }
    //        temp = temp->next;
    //        //last = last->next;
    //    }
    //}
    stu* prev;
    for (int i = 0; i < cnt - 1; i++) {
        prev = NULL;
        last = head;
        while (last->next) {
            if (last->sum < last->next->sum) {
                temp = last->next;
                last->next = last->next->next;
                temp->next = last;
                if (prev) {
                    prev->next = temp;
                }
                else {
                    head = temp;
                }
                prev = temp;
            }
            else {
                prev = last;
                last = last->next;
            }
        }
    }
    system("cls");
    print_List(&head);
    Free_List(&head);
    char return_Last;
    printf("输入任意字符返回上一级");
    scanf(" %c", &return_Last);
}
void analy_Grade_Stu(char* act) {
    system("cls");
    int n = 1, cnt = 0;
    stu* head = NULL;
    char flag;
    cnt = node_Number(cnt);
    if (cnt <= 2) return;
    FILE* fp = fopen("C:\\Users\\30371\\Desktop\\student.txt", "r");
    new_Link_File(&head, fp);
    stu* last = head, * temp = head;
    if (head->sum < head->next->sum) {
        temp = head->next;
        head->next = head->next->next;
        temp->next = head;
        head = temp;
    }
    stu* prev;
    for (int i = 0; i < cnt - 1; i++) {
        prev = NULL;
        last = head;
        while (last->next) {
            if (last->sum < last->next->sum) {
                temp = last->next;
                last->next = last->next->next;
                temp->next = last;
                if (prev) {
                    prev->next = temp;
                }
                else {
                    head = temp;
                }
                prev = temp;
            }
            else {
                prev = last;
                last = last->next;
            }
        }
    }
    last = head;
    while (last && strcmp(last->account, act)) {
        last = last->next;
        n++;
    }
    if (n < 5) {
        printf("本次考试成绩排名为第%d名，成绩优异请继续保持\n", n);
    }
    else if (n <= 15) {
        printf("本次考试成绩排名为第%d名，很不错努力向前追赶\n", n);
    }
    else {
        printf("本次考试成绩排名为第%d名, 有很大进步空间，加油\n", n);
    }
    Free_List(&head);
    printf("(输入任意字符返回上一级)");
    scanf(" %c", &flag);
    return;
}
void grade_Appeal(char* act) {
    int flag = 0, revise = 0;
    system("cls");
    char math[15] = "高数成绩", clag[15] = "C语言成绩";
    printf("选择你要申诉的科目：1.高数成绩\t2.C语言成绩：");
    scanf("%d", &flag);
    printf("\n");
    while (flag != 1 && flag != 2) {
        printf("输入不符合规范，请重新输入：\n");
        scanf("%d", &flag);
    }
    printf("输入需要申诉的科目成绩:\n");
    scanf("%d", &revise);
    while (revise < 0 && revise > 100) {
        printf("输入分数不符合规范，请重新输入：\n");
        scanf("%d", &revise);
    }
    stu* head = NULL;
    FILE* fp = fopen("C:\\Users\\30371\\Desktop\\student.txt", "r");
    new_Link_File(&head, fp);
    stu* last = head;
    while (last && strcmp(last->account, act)) {
        last = last->next;
    }
    FILE* fps = fopen("C:\\Users\\30371\\Desktop\\代办3成绩申诉.txt", "a");
    if (flag == 1) {
        fprintf(fps, "%s\t%s\t%d\t%d", last->name, math, last->math, revise);
    }
    fclose(fps);
    printf("申诉成功，等待管理员核实处理中");
    printf("(输入5返回上一级)");
    scanf("%d", &flag);
    if (flag == 5) {
        return;
    }
    Free_List(&head);
}
void refind_Psd() {
    int math = 0, sum = 0, clag = 0, grade = 0;
    double ave = 0;
    char flag, temp[20] = { 0 }, psd_Find[20] = { 0 }, name[20] = { 0 }, act[20] = { 0 }, psd[20] = { 0 }, num[20] = { 0 }, refind[20] = { 0 };
    system("cls");
    printf("密码找回界面：\n");
    printf("输入你要找回密码的账号：");
    scanf("%s", temp);
    printf("\n");
    stu* head = NULL;
    FILE* fp = fopen("C:\\Users\\30371\\Desktop\\student.txt", "r");
    FILE* fpr = fopen("C:\\Users\\30371\\Desktop\\密码找回.txt", "a");
    while (fscanf(fp, "%s %s %d %d %d %lf %s %s %s", name, num, &math, &clag, &sum, &ave, act, psd, refind) != EOF) {
        if (!strcmp(act, temp)) {
            printf("输入密保以核实身份：");
            scanf("%s", psd_Find);
            printf("\n");
            if (!strcmp(refind, psd_Find)) {
                fprintf(fpr, "%s %s %s\n", name, act, psd_Find);
                fclose(fpr);
                printf("申请已发送，管理员同意后密保将作为新的密码\n输入任意字符返回上一层");
                scanf(" %c", &flag);
                return;
            }
            else {
                printf("密保错误\n输入任意字符返回上一层");
                scanf(" %c", &flag);
                return;
            }
        }
    }
    printf("系统没有该账号，输入任意字符返回上一层");
    scanf(" %c", &flag);
    return;
}
int stu_Login(int flag, char* act) {
    char psd[20];
    printf("输入你的账号:");
    scanf("%10s", act);
    int len = strlen(act);
    printf("\n");
    printf("输入你的密码(忘记密码输入a进行密码找回):");
    scanf("%19s", psd);
    if (!strcmp(psd, "a")) {
        refind_Psd();
        return 0;
    }
    printf("\n");
    stu* head = NULL;
    FILE* fp = fopen("C:\\Users\\30371\\Desktop\\student.txt", "r");
    new_Link_File(&head, fp);
    stu* last = head;
    while (last && (strcmp(last->account, act) || strcmp(last->password, psd))) {
        last = last->next;
    }//||len != 7
    if (!last) {
        printf("账号或密码有误，请重新输入\n");
        flag = 0;
    }
    else {
        flag = 1;
    }
    Free_List(&head);
    return flag;
}
void list_Download() {//文件拷贝
    char address[30] = { 0 }, name[20] = "学生姓名", number[20] = "学生学号", math[20] = "高数成绩", clag[20] = "C语言成绩", sum[20] = "总分", ave[20] = "平均分";
    /*printf("输入文件下载路径");
    scanf("%s", address);*/
    FILE* fpr = fopen("学生成绩单", "w");
    stu* head = NULL, * prev = NULL;
    int cnt = 0;
    cnt = node_Number(cnt);
    FILE* fp = fopen("C:\\Users\\30371\\Desktop\\student.txt", "r");
    new_Link_File(&head, fp);
    stu* last = head, * temp = head;
    if (head->sum < head->next->sum) {
        temp = head->next;
        head->next = head->next->next;
        temp->next = head;
        head = temp;
    }
    for (int i = 0; i < cnt - 1; i++) {
        prev = NULL;
        last = head;
        while (last->next) {
            if (last->sum < last->next->sum) {
                temp = last->next;
                last->next = last->next->next;
                temp->next = last;
                if (prev) {
                    prev->next = temp;
                }
                else {
                    head = temp;
                }
                prev = temp;
            }
            else {
                prev = last;
                last = last->next;
            }
        }
    }
    last = head;
    printf("%-20s%-20s%-20s%-17s%-18s%-15s\n", name, number, math, clag, sum, ave);
    while (last) {
        fprintf(fpr, "%-20s%-15s%-15d%-13d%-15d%-20.2lf\n", last->name, last->number, last->math, last->clag, last->sum, last->ave);
    }
    Free_List(&head);
    fclose(fpr);
}
void analy_Tea() {
    system("cls");
    stu* head = NULL, * prev = NULL;
    int cnt = 0, math_Number = 0, clag_Number = 0;
    cnt = node_Number(cnt);
    FILE* fp = fopen("C:\\Users\\30371\\Desktop\\student.txt", "r");
    new_Link_File(&head, fp);
    stu* last = head, * temp = head;
    while (last) {
        if (last->math < 60) {
            math_Number++;
        }
        if (last->clag < 60) {
            clag_Number++;
        }
        last = last->next;
    }
    printf("班级中有%.1lf%%的人高数不及格，", 100.0 * math_Number / cnt);
    if (100.0 * math_Number / cnt < 20) {
        printf("同学们高数掌握情况较好\n");
    }
    else {
        printf("有较多同学高数不及格，需要加强高数训练\n");
    }
    printf("班级中有%.1lf%%的人C语言不及格,", 100.0 * clag_Number / cnt);
    if (100.0 * clag_Number / cnt < 20) {
        printf("同学们C语言掌握情况较好\n");
    }
    else {
        printf("有较多同学C语言不及格，需要加强C语言训练\n");
    }
    printf("输入9返回上一层\n");
    Free_List(&head);
    char t;
    scanf(" %c", &t);
    return;
}
void remind_Op() {
    system("cls");
    int flag = 1;
    FILE* fp = fopen("C:\\Users\\30371\\Desktop\\待办5成绩更新.txt", "w");
    printf("已提示管理员更新成绩，等待管理员处理\n");
    fprintf(fp, "%d", flag);
    printf("(输入5返回上一级)");
    scanf("%d", &flag);
    if (flag == 5) {
        return;
    }
}
void update() {
    char update;
    FILE* fp = fopen("C:\\Users\\30371\\Desktop\\待办5成绩更新.txt", "r");
    if (fscanf(fp, "%c", &update) != EOF) {
        printf("已更新成绩\n");
    }
    else {
        printf("无相关更新成绩要求\n");
    }
    fclose(fp);
    FILE* fpr = fopen("C:\\Users\\30371\\Desktop\\待办5成绩更新.txt", "w");
    fclose(fpr);
}
void act_Add_Stu() {
    int temp = 0;
    double ave = 0;
    char name[20] = { 0 }, act[20] = { 0 }, psd[20] = { 0 };
    FILE* fp = fopen("C:\\Users\\30371\\Desktop\\student.txt", "a");
    printf("分别输入要添加的账号密码：");
    scanf("%s %s", act, psd);
    printf("\n");
    fprintf(fp, "%s %s %d %d %d %.2lf %s %s %s", name, name, temp, temp, temp, ave, act, psd, name);
    fclose(fp);
}
void act_Add_Tea() {
    char act[20] = { 0 }, psd[20] = { 0 };
    FILE* fp = fopen("C:\\Users\\30371\\Desktop\\教师账号密码.txt", "a");
    printf("分别输入要添加的账号密码：");
    scanf("%s %s", act, psd);
    printf("\n");
    fprintf(fp, "%s %s\n", act, psd);
    fclose(fp);
}
void print_Act() {
    system("cls");
    int math = 0, sum = 0, clag = 0, grade = 0;
    double ave = 0;
    char temp, name[20] = { 0 }, act[20] = { 0 }, psd[20] = { 0 }, num[20] = { 0 }, refind[20] = { 0 };
    FILE* fp_Stu = fopen("C:\\Users\\30371\\Desktop\\student.txt", "r");
    FILE* fp_Tea = fopen("C:\\Users\\30371\\Desktop\\教师账号密码.txt", "r");
    printf("学生账号密码:\n");
    while (fscanf(fp_Stu, "%s %s %d %d %d %lf %s %s %s", name, num, &math, &clag, &sum, &ave, act, psd, refind) != EOF) {
        printf("%s %s %s\n", name, act, psd);
    }
    printf("教师账号密码:\n");
    while (fscanf(fp_Tea, "%s %s", act, psd) != EOF) {
        printf("%s %s\n", act, psd);
    }
    fclose(fp_Stu);
    fclose(fp_Tea);
    printf("输入a返回上一层");
    scanf(" %c", &temp);
    while (temp != 'a') {
        printf("输入违规，请重新输入");
        scanf(" %c", &temp);
    }
    return;
}
void delete_Act() {
    system("cls");
    char act[20] = { 0 };
    printf("输入你要删除的账号：");
    stu* head = NULL;
    FILE* fp = fopen("C:\\Users\\30371\\Desktop\\student.txt", "r");
    new_Link_File(&head, fp);
    while (1) {
        scanf("%s", act);
        printf("\n");
        stu* last = head, * temp = NULL;
        while (last && strcmp(last->account, act)) {
            temp = last;
            last = last->next;
        }
        if (!last) {
            if (strcmp(act, "a")) {
                Free_List(&head);
                break;
            }
            printf("您要删除的账号不存在，请重新输入或输入a返回上一层:");

        }
        else {
            if (last == head) {
                head = head->next;
                free(head);
            }
            else {
                temp->next = last->next;
                free(last);
                last = NULL;
            }
            printf("删除成功\n");
            int math = 0, sum = 0, clag = 0, grade = 0;
            last = head;
            double ave = 0;
            FILE* fp_Stu = fopen("C:\\Users\\30371\\Desktop\\student.txt", "w");
            while (last) {
                fprintf(fp_Stu, "%s %s %d %d %d %lf %s %s %s\n", last->name, last->number, last->math, last->clag, last->sum, last->ave, last->account, last->password, last->find_Password);
                last = last->next;
            }
            Free_List(&head);
            fclose(fp_Stu);
            break;
        }
    }
}
void revise_Act() {
    system("cls");
    char act[20] = { 0 }, psd[20] = { 0 };
    stu* head = NULL;
    FILE* fp = fopen("C:\\Users\\30371\\Desktop\\student.txt", "r");//把文件中的信息复制到链表中
    new_Link_File(&head, fp);
    printf("输入你要修改的账号:");
    while (1) {
        scanf("%s", act);
        stu* last = head;
        while (last && strcmp(last->account, act)) {
            last = last->next;
        }
        if (!last) {
            if (strcmp(act, "a")) {
                Free_List(&head);
                break;
            }
            printf("您要修改的账号不存在，请重新输入或输入a返回上一层:");
        }
        else {
            printf("输入修改后的账号密码：");
            scanf("%s %s", act, psd);
            strcpy(last->account, act);
            strcpy(last->password, psd);
            last = head;
            double ave = 0;
            FILE* fp_Stu = fopen("C:\\Users\\30371\\Desktop\\student.txt", "w");
            while (last) {
                fprintf(fp_Stu, "%s %s %d %d %d %.2lf %s %s %s", last->name, last->number, last->math, last->clag, last->sum, last->ave, last->account, last->password, last->find_Password);
                last = last->next;
            }
            Free_List(&head);
            break;
        }
    }
}
void quer_Act() {
    system("cls");
    int math = 0, sum = 0, clag = 0, grade = 0, flag = -1;
    double ave = 0;
    char flag_Ch, temp[20] = { 0 }, name[20] = { 0 }, act[20] = { 0 }, psd[20] = { 0 }, num[20] = { 0 }, refind[20] = { 0 };
    printf("1.查询学生账号 2.查询教师账号");
    scanf("%d", &flag);
    while (flag != 1 && flag != 2) {
        printf("输入不合法，请重新输入\n");
        printf("1.查询学生账号 2.查询教师账号");
        scanf("%d", &flag);
    }
    printf("输入要查询的账号：");
    scanf("%s", temp);
    if (flag == 1) {
        FILE* fp = fopen("C:\\Users\\30371\\Desktop\\student.txt", "r");
        while (fscanf(fp, "%s %s %d %d %d %lf %s %s %s", name, num, &math, &clag, &sum, &ave, act, psd, refind) != EOF) {
            if (!strcmp(temp, act)) {
                printf("姓名：%s\t账号：%s\t密码：%s\n", name, act, psd);
                printf("(输入任意字符返回上一层)");
                scanf(" %c", &flag_Ch);
                return;
            }
        }
        printf("没有查询到相关账号");
    }
    else {
        FILE* fp = fopen("C:\\Users\\30371\\Desktop\\教师账号密码.txt", "r");
        while (fscanf(fp, "%s %s %s %s", name, act, psd, refind) != EOF) {
            if (!strcmp(temp, act)) {
                printf("姓名：%s\t账号：%s\t密码：%s\n", name, act, psd);
                printf("(输入任意字符返回上一层)");
                scanf(" %c", &flag_Ch);
                return;
            }
        }
        printf("没有查询到相关账号");
    }
    return;
}
void stu_Input() {
    system("cls");
    int flag;
    printf("确定要重新录入学生信息吗，这会导致当前所有学生信息清空\n");
    printf("按1确定清空，按0返回取消并返回上一步");
    scanf("%d", &flag);
    while (flag != 1 && flag != 0) {
        printf("输入违规，请重新输入:");
        scanf("%d", &flag);
    }
    if (flag == 0) {
        return;
    }
    int math = 0, sum = 0, clag = 0, grade = 0;
    double ave = 0;
    char temp[20] = { 0 }, name[20] = { 0 }, act[20] = { 0 }, psd[20] = { 0 }, num[20] = { 0 }, refind[20] = { 0 };
    FILE* fp = fopen("C:\\Users\\30371\\Desktop\\student.txt", "w");
    printf("分别输入学生姓名，学号，高数成绩，C语言成绩，账号，密码，密保(按0返回上一层)\n");
    while (1) {
        scanf("%s", name);
        if (!strcmp(name, "0")) {
            fclose(fp);
            return;
        }
        scanf("%s %d %d %s %s %s", num, &math, &clag, act, psd, refind);
        sum = math + clag, ave = 1.0 * sum / 2;
        fprintf(fp, "%s %s %d %d %d %.2lf %s %s %s\n", name, num, math, clag, sum, ave, act, psd, refind);
    }
    fclose(fp);
    return;
}
void act_Input() {
    int flag;
    system("cls");
    printf("确定要重新录入学生账号密码吗，这会导致当前所有学生账号密码以及密码找回问题清空(但是其他信息均会保留)\n");
    printf("按1确定清空，按0返回取消并返回上一步");
    scanf("%d", &flag);
    while (flag != 1 && flag != 0) {
        printf("输入违规，请重新输入:");
        scanf("%d", &flag);
    }
    if (flag == 0) {
        return;
    }
    FILE* fp = fopen("C:\\Users\\30371\\Desktop\\student.txt", "r");
    stu* head = NULL;
    new_Link_File(&head, fp);
    stu* last = head;
    int math = 0, sum = 0, clag = 0, grade = 0;
    double ave = 0;
    char temp[20] = { 0 }, name[20] = { 0 }, act[20] = { 0 }, psd[20] = { 0 }, num[20] = { 0 }, refind[20] = { 0 };
    FILE* fpr = fopen("C:\\Users\\30371\\Desktop\\student.txt", "w");
    while (last) {
        printf("分别输入%s的新账号密码以及密保（输入0返回上一层）:", last->name);
        scanf("%s", act);
        if (!strcmp(act, "0")) {
            while (last) {
                char t[3] = "0";
                fprintf(fp, "%s %s %d %d %d %lf %s %s %s", last->name, last->number, last->math, last->clag, last->sum, last->ave, t, t, t);
                last = last->next;
            }
            fclose(fpr);
            return;
        }
        scanf("%s %s", psd, refind);
        fprintf(fp, "%s %s %d %d %d %lf %s %s %s\n", last->name, last->number, last->math, last->clag, last->sum, last->ave, act, psd, refind);
        last = last->next;
    }
    Free_List(&head);
    fclose(fpr);
    return;
}
void psd_Revise(char* act) {
    system("cls");
    char flag, psd[19] = { 0 };
    FILE* fp = fopen("C:\\Users\\30371\\Desktop\\student.txt", "r");
    FILE* fp_Write = fopen("C:\\Users\\30371\\Desktop\\学生端密码找回.txt", "a");
    stu* head = NULL;
    new_Link_File(&head, fp);
    stu* last = head;
    while (strcmp(last->account, act)) {
        last = last->next;
    }
    printf("学生密码修改界面:\n");
    printf("输入修改后的密码(最少6位，最多18位)：");
    scanf("%18s", psd);
    printf("\n");
    int len_Psd = strlen(psd);
    while (len_Psd < 6 || len_Psd > 18) {
        printf("不符合规范，请重新输入");
        scanf("%18s", psd);
    }
    fprintf(fp_Write, "%s %s %s", last->name, last->password, psd);
    fclose(fp_Write);
    printf("修改请求已发送至管理端(输入任意字符返回上一层)");
    scanf(" %c", &flag);
    Free_List(&head);
}
void te_Link(tact** head) {
    char name[20] = { 0 }, act[20] = { 0 }, psd[20] = { 0 }, psd_Find[10] = { 0 };
    FILE* fp = fopen("C:\\Users\\30371\\Desktop\\教师账号密码.txt", "r");
    tact* p = NULL;
    while (fscanf(fp, "%s %s %s %s", name, act, psd, psd_Find) != EOF) {
        p = (tact*)malloc(sizeof(tact));
        strcpy(p->name, name);
        strcpy(p->account, act);
        strcpy(p->password, psd);
        strcpy(p->find_Psd, psd_Find);
        p->next = NULL;
        if (!*head) {
            *head = p;
        }
        else {
            tact* last = *head;
            while (last->next) {
                last = last->next;
            }
            last->next = p;
        }
    }
}
void te_Re(char* act_B) {//教师修改密码
    int len;
    char flag = '9', temp[20] = { 0 }, name[20] = { 0 }, act[20] = { 0 }, psd[20] = { 0 }, psd_Re[20] = { 0 }, psd_Find[10] = { 0 };
    printf("修改密码需输入密保确认身份：");
    scanf("%s", temp);
    printf("\n");
    FILE* fp = fopen("C:\\Users\\30371\\Desktop\\教师账号密码.txt", "r");
    while (fscanf(fp, "%s %s %s %s", name, act, psd, psd_Find)) {
        if (!strcmp(act, act_B)) {
            if (!strcmp(temp, psd_Find)) {
                printf("输入修改后的密码（至少6位）：");
                scanf("%18s", psd_Re);
                int len = strlen(psd_Re);
                while (len < 6) {
                    printf("输入不符规范，请重新输入：");
                    scanf("%18s", psd_Re);
                    int len = strlen(psd_Re);
                }
                FILE* fpp = fopen("C:\\Users\\30371\\Desktop\\教师密码修改待办.txt", "a");
                fprintf(fpp, "%s %s %s", name, psd, psd_Re);
                fclose(fpp);
                printf("修改申请已提交，等待管理端同意\n");
                printf("输入任意字符返回\n");
                scanf(" %c", &flag);
                return;
            }
            else {
                printf("密保错误,输入任意字符返回\n");
                scanf(" %c", &flag);
            }
        }
    }
}
void to_Do() {
    char flag, name[20] = { 0 }, number[20] = { 0 }, act[20] = { 0 }, psd[20] = { 0 }, psd_Find[10] = { 0 };
    int agree = 0;
    system("cls");
    printf("待办事项:\n");
    printf("\n");
    printf("待办事项1.学生注册账号：");
    FILE* fp = fopen("C:\\Users\\30371\\Desktop\\待办1学生.txt", "r");
    if (fscanf(fp, "%s %s %s %s %s", name, number, act, psd, psd_Find) != EOF)
    {
        printf("学生姓名\t学生学号\t账号\t\t密码\n");
    }
    else {
        printf("(暂无学生账号注册)\n");
    }
    while (fscanf(fp, "%s %s %s %s %s", name, number, act, psd, psd_Find) != EOF)
    {
        printf("%16s%16s%16s%16s%16s\n", name, number, act, psd, psd_Find);
        printf("1.同意注册申请  0.不同意注册申请\n");
        scanf("%d", &agree);
        while (agree != 1 && agree != 0) {
            printf("输入违规，请重新输入\n");
            scanf("%d", &agree);
        }
        if (agree) {
            stu* head = NULL;
            FILE* fps = fopen("C:\\Users\\30371\\Desktop\\student.txt", "r");
            new_Link_File(&head, fps);
            stu* last = head;
            fclose(fps);
            FILE* fpw = fopen("C:\\Users\\30371\\Desktop\\student.txt", "w");
            while (last && strcmp(last->name, name)) {
                fprintf(fpw, "%s %s %d %d %d %.2lf %s %s %s\n", last->name, last->number, last->math, last->clag, last->sum, last->ave, last->account, last->password, last->find_Password);
                last = last->next;
            }
            if (!last) {
                printf("学生系统没有该同学信息，必须先添加对应信息后才能为该同学注册账号\n");
            }
            else {
                strcpy(last->account, act);
                strcpy(last->password, psd);
                strcpy(last->find_Password, psd_Find);
                fprintf(fpw, "%s %s %d %d %d %.2lf %s %s %s\n", last->name, last->number, last->math, last->clag, last->sum, last->ave, last->account, last->password, last->find_Password);
            }
            last = last->next;
            while (last) {
                fprintf(fpw, "%s %s %d %d %d %.2lf %s %s %s\n", last->name, last->number, last->math, last->clag, last->sum, last->ave, last->account, last->password, last->find_Password);
                last = last->next;
            }
            Free_List(&head);
        }
        else {
            printf("已驳回账号申请\n");
        }
    }
    FILE* fp_Empty_Apy1 = fopen("C:\\Users\\30371\\Desktop\\待办1学生.txt", "w");//清空处理好的文件
    fclose(fp_Empty_Apy1);
    printf("教师注册账号:");
    char act_Tea[20] = { 0 }, psd_Tea[20] = { 0 }, name_Tea[20] = { 0 }, find[20] = { 0 };
    FILE* fpr = fopen("C:\\Users\\30371\\Desktop\\待办1教师.txt", "r");
    while (fscanf(fpr, "%s %s %s %s", name_Tea, act_Tea, psd_Tea, find) != EOF)
    {
        printf("%s %s %s %s\n", name_Tea, act_Tea, psd_Tea, find);
        printf("1.同意注册申请  0.不同意注册申请\n ");
        scanf("%d", &agree);
        while (agree != 1 && agree != 0) {
            printf("输入违规，请重新输入\n");
        }
        if (agree) {
            FILE* fpp = fopen("C:\\Users\\30371\\Desktop\\教师账号密码.txt", "a");
            fprintf(fpp, "%s %s %s %s\n", name_Tea, act_Tea, psd_Tea, find);
            fclose(fpp);
        }
        else {
            printf("已驳回账号申请\n");
            printf("\n");
        }
    }
    FILE* fp_Empty_Apy = fopen("C:\\Users\\30371\\Desktop\\待办1教师.txt", "w");//清空处理好的文件
    fclose(fp_Empty_Apy);

    //密码找回
    printf("待办2.找回密码申请：\n");
    printf("\n");
    FILE* fp_Find = fopen("C:\\Users\\30371\\Desktop\\密码找回.txt", "r");
    if (fscanf(fp_Find, "%s %s %s", name, act, psd_Find) == EOF) {
        printf("暂无密码找回申请\n");
    }
    else {
        printf("%s %s %s\n", name, act, psd_Find);
        printf("1.同意找回申请  0.不同意找回申请\n ");
        scanf("%d", &agree);
        while (agree != 1 && agree != 0) {
            printf("输入违规，请重新输入\n");
        }
        if (agree) {
            FILE* fp_Re_Psd = fopen("C:\\Users\\30371\\Desktop\\student.txt", "r");
            stu* head_Refind = NULL;
            new_Link_File(&head_Refind, fp_Re_Psd);
            FILE* fp_Revise_Psd = fopen("C:\\Users\\30371\\Desktop\\student.txt", "w");
            stu* last_Refind = head_Refind;
            last_Refind = head_Refind;
            while (last_Refind) {
                if (!strcmp(last_Refind->account, act)) {
                    fprintf(fp_Revise_Psd, "%s %s %d %d %d %.2lf %s %s %s\n", last_Refind->name, last_Refind->number, last_Refind->math, last_Refind->clag, last_Refind->sum, last_Refind->ave, last_Refind->account, last_Refind->find_Password, last_Refind->find_Password);
                }
                else
                {
                    fprintf(fp_Revise_Psd, "%s %s %d %d %d %.2lf %s %s %s\n", last_Refind->name, last_Refind->number, last_Refind->math, last_Refind->clag, last_Refind->sum, last_Refind->ave, last_Refind->account, last_Refind->password, last_Refind->find_Password);
                }
                last_Refind = last_Refind->next;
            }
            fclose(fp_Revise_Psd);
        }
        else {
            printf("已驳回密码找回申请\n");
        }
    }
    printf("\n");
    FILE* fp_Empty_Re = fopen("C:\\Users\\30371\\Desktop\\密码找回.txt", "w");//清空处理好的文件
    fclose(fp_Empty_Re);
    //待办之密码修改
    printf("待办三之密码修改：\n");
    char name_Rev[20] = "学生姓名", psd_Init[20] = "原密码", psd_Rev[20] = "修改后密码";
    char name_R[20] = { 0 }, psd_R[20] = { 0 }, psd_A[20] = { 0 };
    FILE* fp_Psd = fopen("C:\\Users\\30371\\Desktop\\学生端密码修改.txt", "r");
    if (fscanf(fp_Psd, "%s %s %s", name_R, psd_R, psd_A) == EOF) {
        printf("暂无学生修改密码需要\n");
    }
    else {
        printf("%-20s%-20s%-20s\n", name_Rev, psd_Init, psd_Rev);
        printf("%-15s%-18s%20s\n", name_R, psd_R, psd_A);
        int flag_Rev = -1;
        printf("1.同意修改 2.不同意修改\n");
        scanf("%d", &flag_Rev);
        while (flag_Rev != 1 && flag_Rev != 2) {
            printf("输入不符合规范，请重新输入:");
            scanf("%d", &flag_Rev);
            printf("\n");
        }
        if (flag_Rev == 2) {
            printf("已驳回修改申请");
        }
        else {
            stu* head = NULL;
            FILE* f = fopen("C:\\Users\\30371\\Desktop\\student.txt", "r");
            new_Link_File(&head, f);
            stu* last = head;
            while (last && strcmp(last->name, name_R)) {
                last = last->next;
            }
            strcpy(last->password, psd_A);
            last = head;
            fclose(f);
            FILE* f_W = fopen("C:\\Users\\30371\\Desktop\\student.txt", "w");
            while (last) {
                te_St_Out(last->name, last->number, last->math, last->clag, last->account, last->password, last->find_Password, f_W);
                last = last->next;
            }
            fclose(f_W);
            Free_List(&head);
        }
    }
    printf("\n");
    FILE* fp_P = fopen("C:\\Users\\30371\\Desktop\\学生端密码修改.txt", "w");//清空处理过的文件
    fclose(fp_P);
    //教师密码修改
    char name_Te[20] = "教师姓名", psd_Be[20] = "原密码", psd_Af[20] = "修改后密码";
    FILE* fp_Te = fopen("C:\\Users\\30371\\Desktop\\教师密码修改待办.txt", "r");
    if (fscanf(fp_Te, "%s %s %s", name, act, psd) == EOF) {
        printf("暂无教师修改密码需要\n");
        printf("\n");
    }
    else{
        rewind(fp_Te);
        printf("%-15s%-15s%-15s\n", name_Te, psd_Be, psd_Af);
        while (fscanf(fp_Te, "%s %s %s", name, psd, psd_Af) != EOF) {
            printf("%-12s%-13s%-13s\n", name, psd, psd_Af);
            printf("1.同意密码修改申请 2.不同意密码修改申请\n");
            scanf(" %c", &flag);
            printf("\n");
            while (flag != '1' && flag != '2') {
                printf("输入违规，请重新输入");
                printf("1.同意密码修改申请 2.不同意密码修改申请\n");
                scanf("%c", &flag);
            }
            if (flag == '1') {
                tact* head = NULL;
                te_Link(&head);
                tact* last = head;
                while (last && strcmp(name, last->name)) {
                        last = last->next;
                }
                strcpy(last->password, psd_Af);
                last = head;
                FILE* fpp = fopen("C:\\Users\\30371\\Desktop\\教师账号密码.txt", "w");
                while (last) {
                    fprintf(fpp, "%s %s %s %s\n", last->name, last->account, last->password, last->find_Psd);
                    last = last->next;
                }
                fclose(fpp);
                last = head;
                while (head) {
                    last = head->next;
                    free(head);
                    head = last;
                }
                FILE*te_Clear = fopen("C:\\Users\\30371\\Desktop\\教师密码修改待办.txt", "w");
                fclose(te_Clear);
                printf("已修改对应账号密码\n");
            }
            else {
                printf("已驳回密码修改申请\n");
            }
        }
    }
    printf("\n");
    //待办之成绩申诉
    printf("待办四之成绩申诉:\n");
    FILE* fp_Appeal = fopen("C:\\Users\\30371\\Desktop\\代办3成绩申诉.txt", "r");
    char name_C[20] = "申诉学生姓名", subject_C[20] = "申诉科目", grade_Before[15] = "原成绩", grade_After[15] = "申诉成绩";
    char subject[15] = { 0 }, name_APPeal[20] = { 0 };
    int before = 0, after = 0;
    while (fscanf(fp_Appeal, "%s %s %d %d", name_APPeal, subject, &before, &after) != EOF) {
        printf("%-20s%-15s%-15s%-15s\n", name_C, subject_C, grade_Before, grade_After);
        printf("%-17s%-15s%-15d%-15d\n", name_APPeal, subject, before, after);
        printf("同意申诉输入1，不同意输入0\n");
        scanf("%d", &agree);
        while (agree != 1 && agree != 0) {
            printf("输入违规，请重新输入\n");
            scanf("%d", &agree);
        }
        if (agree == 0) {
            printf("已拒绝该学生成绩申诉\n");
        }
        else {
            FILE* fp = fopen("C:\\Users\\30371\\Desktop\\student.txt", "r");
            stu* head = NULL;
            new_Link_File(&head, fp);
            stu* last = head;
            while (strcmp(name_APPeal, last->name)) {
                last = last->next;
            }
            if (!strcmp(subject, "高数成绩")) {
                last->math = after;
                last->sum = last->math + last->clag;
                last->ave = last->sum / 2;
            }
            else {
                last->clag = after;
                last->sum = last->math + last->clag;
                last->ave = last->sum / 2;
            }
            last = head;
            FILE* fp_W_App = fopen("C:\\Users\\30371\\Desktop\\student.txt", "w");
            while (last) {
                te_St_Out(last->name, last->number, last->math, last->clag, last->account, last->password, last->find_Password, fp_W_App);
                last = last->next;
            }
            printf("已修改该学生成绩\n");
            FILE* fp_Empty_App = fopen("C:\\Users\\30371\\Desktop\\代办3成绩申诉.txt", "w");//清空处理好的文件
            fclose(fp_Empty_App);
            Free_List(&head);
        }
    }
    printf("\n");
    //更新成绩
    printf("待办五之成绩更新：\n");
    update();
    printf("\n");
    //输出
    printf("(输入任意字符返回上一层)");
    scanf(" %c", &flag);
    return;
}
int main() {
    int t = -1, fnc, flag = 0, temp = 1;
    printf("1.登录账号 2.注册账号\n");
    scanf("%d", &fnc);
    if (fnc == 2) {
        account_Register();
    }
    char port[20];
    do {
        system("cls");
        if (t != 3)
        {
            printf("选择你的端口:1.学生登录 2.教师登录 3.管理员登录(按0退出):\n");
            scanf("%5s", port);
            if (!strcmp(port, "0")) {
                break;
            }
        }
        if (!strcmp("1", port)) {
            system("cls");
            int log_Flag = -1;
            char act[20] = { 0 };
            while (stu_Login(log_Flag, act) != 1);
            while (1) {
                system("cls");
                printf("学生端界面\n");
                printf("选择你要进行的操作：\n1.成绩查询\n2.查询本班成绩\n3.成绩分析\n4.成绩申诉\n5.返回上一层\n6.修改密码\n0.退出\n");
                scanf("%d", &flag);
                switch (flag) {
                case 1:quer_Self(act);
                    break;
                case 2:list_Sort();
                    break;
                case 3:analy_Grade_Stu(act);
                    break;
                case 4:grade_Appeal(act);
                    break;
                case 5:temp = 0;
                    break;
                case 6:psd_Revise(act);
                case 0:return 0;
                default:printf("违规输入，请重新输入");
                }
                if (temp == 0) {
                    break;
                }
            }
        }
        else if (!strcmp("2", port) || t == 3) {
            int flag = 0, temp = 1; 
            char name[20] = { 0 }, act[20] = { 0 }, psd[20] = { 0 }, find[20] = { 0 }, act_Temp[20] = { 0 }, psd_Temp[20] = { 0 };
            system("cls"); 
            if (t != 3) {
                FILE* fp = fopen("C:\\Users\\30371\\Desktop\\教师账号密码.txt", "r");
                if (fscanf(fp, "%s %s %s %s", name, act, psd, find) == EOF) {
                    printf("教师端暂时无法登录,输入任意字符返回上一层\n");
                    char t;
                    scanf(" %c", &t);
                }
                fclose(fp);
                FILE* fpp = fopen("C:\\Users\\30371\\Desktop\\教师账号密码.txt", "r");
                printf("输入你的账号：");
                scanf("%s", act_Temp);
                printf("\n");
                printf("输入你的密码：");
                scanf("%s", psd_Temp);
                printf("\n");
                while (fscanf(fp, "%s %s %s %s", name, act, psd, find) != EOF) {
                    if (!strcmp(act, act_Temp)) {
                        while (1) {
                            if (!strcmp(psd, psd_Temp)) {
                                break;
                            }
                            else {
                                printf("密码错误，请重新输入");
                            }
                        }
                    }
                }
            }
            while (1) {
                t = -1;//避免上次管理员进入后t一直为3
                system("cls");
                printf("教师端界面\n");
                printf("选择你要进行的操作:\n");
                printf("1.增加新的学生信息\n2.删除学生信息\n3.修改学生信息\n4.查询学生信息\n5.输出本班成绩\n");
                printf("6.下载至文件\n7.成绩分析\n8.提醒管理员进行成绩的更新\n9.返回上一层\n0.退出\n101.修改密码\n");
                stu* head = NULL;
                stu* head2 = NULL;
                stu* head3 = NULL;
                scanf("%d", &flag);
                switch (flag) {
                case 1:Stu_List(&head);
                    Free_List(&head);
                    break;
                case 2:Delete_stu();
                    Free_List(&head2);
                    break;
                case 3:revise_Stu();
                    break;
                case 4:quer();
                    break;
                case 5:list_Sort();
                    break;
                case 6:list_Download();
                    break;
                case 7:analy_Tea();
                    break;
                case 8:remind_Op();
                    break;
                case 9:temp = 0;
                    break;
                case 0:return 0;
                case 101:te_Re(act_Temp);
                }
                if (temp == 0) {
                    break;
                }
            }
        }
        else if (!strcmp("3", port)) {
            system("cls");
            printf("管理员端界面");
            printf("选择你要进行的操作:");
            printf("1.查看待办事项\n2.进入教师端进行信息修改\n3.增加账号及密码\n4.删除账号及密码\n5.修改账号及密码\n6.查找账号及密码\n");
            printf("7.录入所有账号及密码\n8.输出所有账号及密码\n9.重新录入所有学生信息\na.返回上一层\n0.退出程序\n");
            char temp;
            while (1) {
                scanf(" %c", &temp);
                if (temp == '1') {
                    to_Do();
                    break;
                }
                else if (temp == '2') {
                    t = 3;
                    break;
                }
                else if (temp == '3') {
                    printf("选择增加 1.学生账号 2.教师账号");
                    int act = 0;
                    scanf("%d", &act);
                    while (act != 1 && act != 2) {
                        printf("输入不合规，请重新输入");
                        scanf("%d", &act);
                    }
                    if (act == 1) {
                        act_Add_Stu();
                    }
                    else {
                        act_Add_Tea();
                    }
                    break;
                }
                else if (temp == '4') {
                    delete_Act();
                    break;
                }
                else if (temp == '5') {
                    revise_Act();
                    break;
                }
                else if (temp == '6') {
                    quer_Act();
                    break;
                }
                else if (temp == '7') {
                    act_Input();
                    break;
                }
                else if (temp == '8') {
                    print_Act();
                    break;
                }
                else if (temp == '9') {
                    stu_Input();
                    break;
                }
                else if (temp == 'a') {
                    break;
                }
                else if (temp == '0') {
                    t = 1;
                    break;
                }
                else {
                    printf("输入不符合规范，请重新输入");
                }
            }
            if (t == 1) {
                break;
            }
        }
        else printf("输入不符合规范，请重新输入：");
    } while (1);
    return 0;
}