package ������_42889;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class Solution_42889 {

	public static int[] solution(int N, int[] stages) {
		int []answer = new int[N];	
		Map<Integer,Double> map = new HashMap<Integer,Double>();//key�� value�� ����ϱ� ���� hashmap
		int stage_length = 0;//������ �ʴ� stage ����
		int stage_length1 = 0; // ���ϴ� stage����
		
		//������� �ƴ� ����Ǯ�̿����� �ʿ��� �ڵ�
		/*
		 * for(int i=0;i<stages.length;i++) { if(stages[i]!=0) {
		 * 
		 * stage_length++; } else break; }
		 */
		stage_length = stages.length;//���� stage ���� ����	
		int count = 0;
		stage_length1 = stage_length;//���ʿ� ���� stage���� ����
		for(int i=1;i<=N;i++)
		{
			
			 if(stage_length1 <=0) //�� �ܰ迡 �Ѱ��� �������� ������� 
				 stage_length1 = 1; //stage_length1 �� 1�� ����� ��� ������ ���꿡�� ���� �ȳ�
			 
			count = 0;
			for(int j=0;j<stage_length;j++)
			{
				if(i==stages[j])//��ä Ž��
					count++;
			}
			if(count==0)//������� i���� �ܰ迡 0 �� ����
				map.put(i, 0.0);
			else//1���̻� ������ ��� �����ؼ� haspmap�� ����
			map.put(i, (double)count/stage_length1);
		
			stage_length1-=count;//��ü stage���� count�� ��ŭ ����
		}

		
		int count_temp = 0;
		Iterator<Integer> it = sortByValue(map).iterator(); //value ������ ����
		while(it.hasNext()){//answer�� ����
			int temp = (Integer) it.next();
				answer[count_temp] = temp;
				count_temp++;
			  }	 
		return answer;
	}
    public static List<Integer> sortByValue(final Map<Integer, Double> map){
        List<Integer> list = new ArrayList<Integer>();//Ű �� ������ ���� list ����
        list.addAll(map.keySet());//list�� keyset ����

        Collections.sort(list,new Comparator<Object>(){//����
        	@SuppressWarnings("unchecked")
			public int compare(Object o1, Object o2) {
        	Object val1 = map.get(o1);
        	Object val2 = map.get(o2);
	
        	if(val1.equals(val2))	//value���� ������ ��� Ű�� ������������ ����
        		return Integer.parseInt(o1.toString()) < Integer.parseInt(o2.toString()) ? 1: -1;
        	else//�ٸ���� value ��������
        		return ((Comparable<Object>)val1).compareTo(val2);
        	}
        	});
        Collections.reverse(list); //������������ ����
        return list;
    }


	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scanner = new Scanner(System.in);
		
		int N = scanner.nextInt();
		int stages[] = new int[2000001];
		for(int i=0;i<stages.length;i++)
		{
			stages[i] = 0;
		}
		int answer[] = new int[N+1];
		for(int i=0;i<=4;i++)
		{
			
			stages[i] = scanner.nextInt();
		}
		
		answer = solution(N,stages);
		
		  for(int i = 0;i<N;i++) { 
			  
			  System.out.print(answer[i]); 
			if(i!=N-1)
				System.out.print(", ");
		  }
		 
		System.out.println();
		
		scanner.close();
	}

}
