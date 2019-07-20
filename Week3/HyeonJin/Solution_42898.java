package ���_42898;

import java.util.Scanner;

public class Solution_42898 {
	 public static int solution(int m, int n, int[][] puddles) {
		 int arr[][] = new int[101][101];//�ִ� 100��
		 int arr1[][] = new int[101][101];
		 //arr , arr1 �迭 0���� �ʱ�ȭ
		 for(int i=0;i<arr.length;i++)
			{
				for(int j=0;j<arr[i].length;j++)
				{
					arr[i][j] = 0;
					arr1[i][j] = 0;
				}
			}
		 //���� ��ġ �� -1�� �������
		 for(int i=0;i<puddles.length;i++)
		 {
				 arr1[puddles[i][0]][puddles[i][1]]  = -1;

		 }
		 //�� ó�� ���� ��ġ
		 arr[1][1] = 1;
		
		 for (int i = 1; i <= m; i++)
			{
				for (int j = 1; j <= n; j++)
				{
					//�����ϰ��
						if (arr1[i][j]== -1)
						{
							arr[i][j] = 0;	//������ ��� �ִܰ���� �� 0���� �������
						}
						else
						{
							if (i == 1 && j == 1)
								arr[i][j] = 1;
							else {
								//Ư�� ��ǥ(i,j)�� �ִ� ��� ������  (i-1,j)�� �ִܰ���� �� + (i,j-1)�� �ִ� ��μ��� �� 
								//�̶� 1000000007�� �ʰ��ϴ� ��찡 �ֱ� ������ ���ϱ� �� 1000000007���� �׻� ������� ��
								arr[i][j] = (arr[i - 1][j]%1000000007) + (arr[i][j - 1]%1000000007);	
							}	
						}
				}
			}
			return arr[m][n] % 1000000007;
	    }
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scanner = new Scanner(System.in);
		int m = scanner.nextInt();
		int n = scanner.nextInt();
		
		int arr[][] = new int[101][101];
		int arr1[][] = new int[2][2];
		for(int i=0;i<arr.length;i++)
		{
			for(int j=0;j<arr[i].length;j++)
			{
				arr[i][j] = 0;
		
			}
		}
		//�׽�Ʈ ���̽�
		arr1[0][0] = 2;
		arr1[0][1] = 2;
		arr1[1][0] = 3;
		arr1[1][1] = 2;
		arr[m][n] = solution(m,n,arr1);
		
		System.out.println(arr[m][n]);
		
		scanner.close();
	}

}
