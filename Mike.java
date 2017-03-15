/**
 * Created by Andrei on 11.03.2017.
 */
import java.util.Scanner;
public class Mike {
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        int l,m,n;
        System.out.println("Введите размер матрицы LxMxN");
        System.out.print("L=");
        l=sc.nextInt();
        System.out.print("M=");
        m=sc.nextInt();
        System.out.print("N=");
        n=sc.nextInt();
        int[][][] k=new int[l][m][n];
        System.out.println("Вывод матрицы с веденными размерами");
            for (int i = 0; i < l; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    for (int q = 0; q < n; q++)
                    {
                        int a = 0, b = 2;
                        k[i][j][q] = a + (int) (Math.random() * b);
                        System.out.print(k[i][j][q] + " ");
                    }
                    System.out.println();
                }
                System.out.println();
            }
        System.out.println("Матрица первой тени:");
        for (int i=0;i<l;i++)
            {
                for (int j=0;j<m;j++)
                {

                    System.out.print(k[i][j][0]);
                }
                System.out.println();
            }
        System.out.println("Матрица второй тени:");
        for (int i=0;i<l;i++)
        {
            for (int j=0;j<n;j++)
            {

                System.out.print(k[i][0][j]);
            }
            System.out.println();
        }
        System.out.println("Матрица третьей тени:");
        for (int i=0;i<m;i++)
        {
            for (int j=0;j<n;j++)
            {

                System.out.print(k[0][i][j]);
            }
            System.out.println();
        }
    }
}
