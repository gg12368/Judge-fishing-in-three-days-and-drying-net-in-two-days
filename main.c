#include<stdio.h>
#include<stdlib.h>
int year;
int openFile(){
	FILE *fp;
	char ch,filename[10];
	printf("输入你想将日期保存的.txt文件名称(eg: G.txt):");
	scanf("%s",filename);
	if((fp = fopen(filename,"w"))==NULL){
		printf("无法打开");
		exit(0);
	}
	ch = getchar();
	printf("请将上述日期输入（以#结束）\n");
	ch = getchar();
	while(ch != '#'){

		fputc(ch,fp);
		putchar(ch);
		ch = getchar();
	}
	fclose(fp);
	putchar(10);
	return 0;
}
int main()
{	FILE *fp;
    int year=0, month=0, day=0;
    int i;
    int sum = 0;
    int m[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };//平年每月天数
    int n[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };//闰年每月天数
    printf("某人从2010年1月1日起开始“三天打鱼两天晒网”，问这个人在以后的某一天中是“打渔”还是“晒网”。\n");
    while (true)
    {
        printf("输入查询日期（用/隔开）：");
        while (true)
        {
            scanf("%d/%d/%d", &year, &month, &day);
            if (year < 2010 || month>12 ||month<1||day<1|| day > 31)
            {
                printf("输入错误,请重新输入：");
                continue;
            }
            else
            {
                break;
            }//判断年月日是否符和要求
        }//判断输入格式的正确性

        for (i = 2010;i < year;i++)
        {
            if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)

                sum += 366;//是闰年
            else   sum += 365;//不是闰年
        }
        for (i = 1;i < month;i++)
        {
            sum += m[i - 1];//不是闰年
            if ((year % 4 == 0 && year % 100 == 0) || year % 400 == 0)
            {
                sum += n[i - 1];//是闰年
            }
        }
        sum += day;
        if (sum % 5 <= 3 && sum % 5 > 0)
            printf("这天打渔\n");
        else
            printf("这天晒网\n");
		openFile();
		break;

    }
        return 0;
}
