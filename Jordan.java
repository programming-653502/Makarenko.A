/**
 * Created by Andrei on 01.03.2017.
 */
import java.util.Scanner;

public class Jordan {
    public static double right(double x,double sinx,double e)
    {
        double sum=0;
        int i=1;
        while (Math.abs(sum-sinx)>e)
        {
                i++;
                double sum2=0;
                for (int j=1;j<=i;j++)
                {
                    sum2+=(2*j-1);
                }
                sum+=Math.pow(x,2*i-1)* Math.pow(-1,i-1)/sum2;

        }
        return i;
    }
    public static double input()
    {
        Scanner sc=new Scanner(System.in);
        int j=1;
        int h=0;
        String s="";
        char[] ch;
        while(j>0)
        {
            j=1;
            System.out.println("Введите число!");
            s = sc.nextLine();
            ch = s.toCharArray();
            for (int i = 0; i < s.length(); i++) {

                if (i==1) {
                    switch (ch[i]) {
                        case '0':
                            break;
                        case '1':
                            break;
                        case '2':
                            break;
                        case '3':
                            break;
                        case '4':
                            break;
                        case '5':
                            break;
                        case '6':
                            break;
                        case '7':
                            break;
                        case '8':
                            break;
                        case '9':
                            break;
                        case '.':
                            break;
                        default: {
                            System.out.println("Введены недопустимые символы, попробуйте снова!");
                            j++;
                        }
                    }
                }else
                {
                    switch (ch[i]) {
                        case '0':
                            break;
                        case '1':
                            break;
                        case '2':
                            break;
                        case '3':
                            break;
                        case '4':
                            break;
                        case '5':
                            break;
                        case '6':
                            break;
                        case '7':
                            break;
                        case '8':
                            break;
                        case '9':
                            break;
                        case '.':{
                            System.out.println("Введены недопустимые символы, попробуйте снова!");
                            j++;
                            break;
                        }
                        default: {
                            System.out.println("Введены недопустимые символы, попробуйте снова!");
                            j++;
                        }
                    }
                }
            }
            if (j==1) {
                j = 0;
            }
        }
        double x;
        x=Double.parseDouble(s);
        return x;
    }
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("Ввод x в радианах!");
        double x;
        x=input();
        double sinx=Math.sin(x);
        System.out.println("Введите погрешность e!");
        double e;
        e=input();
        int n=(int)right(x,sinx,e);
        System.out.println("Ответ="+n);
    }
}
