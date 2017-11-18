const int con_int1 = +1, con_int2 = -1 , con_int3 = 0,con_int4 = 10;
const char con_ch4 = 'a';                            //常量说明部分的测试

int index , var_arr[10] , bigger_input;
char var_arr_ch[10];                                //变量说明的测试

int find_bigger(int a, int b)
{
    if(a >= b)
        return(a);
    return(find_bigger(a+1,b));
}                                                  //一个返回两个整型数之中较大的数的简单函数，用递归的效果实现

void print_bigger()
{
    printf("The bigger number is ",bigger_input);
}                                                 //无返回值的打印全局变量bigger_input的函数

void relation(int a,int b)                     //比较两个输入参数大小关系从而打印不同的字符串的无返回值函数
{
    const sml_eql = 0, bgr_eql = 1;

    int re;

    if(a <= b)             //测试条件语句
    {
        re = sml_eql;
        printf("input3 is smaller or equal than input4");
    }
    if(a >= b)
    {
        re = bgr_eql;
        printf("input3 is bigger or equal than input4");
    }
    if(a != b)
    {
        ;             //测试空语句
    }
    if(a == b)
    {
        printf("input3 is equal to input4")
    }
    swich(re)         //测试情况语句
    {
        case 0;
        {
            if(a < b)
            {
                printf("input3 is smaller than input4")
            }
        }
        case 1;
        {
            if(a > b)
            {
                printf("input3 is bigger than input4");
            }
        }
    }
}

void main()
{
    int input1,input2;
    int input3,input4;

    scanf(input1,input2);
    scanf(input3,input4);               //测试读语句

    index = 0;
    bigger_input = find_bigger(input1,input2);             //调用可递归的find_bigger
    print_bigger();                     	//打印由find_bigger找出的bigger_input

    relation(input3,input4);

    printf(-input3 + input4 * (input3 /-1) * 'a' + find_bigger(input3,input4) * 7 );   //测试表达式部分

    do
    {
        var_arr[index] = index*2 + 1;
        var_arr_ch[index] = con_ch4 + index;
        printf(var_arr[index] );
        printf(var_arr_ch[index]);           //至此，printf语句的三种形式全部测试完毕
        index = index + 1;

    }while(index < con_int4)          //测试循环语句部分
}
