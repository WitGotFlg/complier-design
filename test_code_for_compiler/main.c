const int con_int1 = +1, con_int2 = -1 , con_int3 = 0,con_int4 = 10;
const char con_ch4 = 'a';

int index , var_arr[10] , bigger_input;
char var_arr_ch[10];

int find_bigger(int a, int b)
{
    if(a >= b)
        return(a);
    return(find_bigger(a+1,b));
}

void print_bigger()
{
    printf("The bigger number is ",bigger_input);
}

void relation(int a,int b)
{
    const sml_eql = 0, bgr_eql = 1;

    int re;

    if(a <= b)
    {
        re = sml_eql;
        printf("left is smaller or equal than right");
    }
    if(a >= b)
    {
        re = bgr_eql;
        printf("left is bigger or equal than right");
    }
    if(a != b)
    {
        printf("left is not equal to right");
    }
    if(a == b)
    {
        printf("left is equal to right")
    }
    swich(re)
    {
        case 0;
        {
            if(a < b)
            {
                printf("left is smaller than right")
            }
        }
        case 1;
        {
            if(a > b)
            {
                printf("left is bigger than right");
            }
        }
    }


}


void main()
{
    int input1,input2;
    int input3,input4;

    scanf(input1,input2);
    scanf(input3,input4);

    index = 0;
    bigger_input = find_bigger(input1,input2);
    print_bigger();

    relation(input3,input4);

    printf(-input3 + input4 * (input3 / ) * 'a' + find_bigger(input3,input4) * 7 )

    do
    {
        var_arr[index] = index*2 + 1;
        var_arr_ch[index] = con_ch4 + index;
        printf(var_arr[index] );
        printf(var_arr_ch[index]);
        index = index + 1;

    }while(index < con_int4)


}
