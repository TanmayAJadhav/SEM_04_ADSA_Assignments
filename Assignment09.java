import java.util.Scanner;

class Heap_sort
{
	private int arr[];
	private int size;
	public Heap_sort(int s)
	{
		size = s;
		arr = new int[size]; 
	}
	void accept()
	{
		Scanner sobj = new Scanner(System.in);
		System.out.println("Enter elements : ");
		for(int i = 0; i < size; i++)
		{
			arr[i] = sobj.nextInt(); 	
		}
		sobj.close();
	}
	
	void sort()
	{
		int length = arr.length;
		for(int i = (length/2)-1; i >= 0; i--)
		{
			heapify(arr, length, i);
		}
		
		for(int i = length-1; i > 0; i--)
		{
			int temp = arr[0];
			arr[0] = arr[i];
			arr[i] = temp;
			
			heapify(arr, i, 0);
		}	
	}
	
	void heapify(int arr[], int length, int index)
	{
		int parent = index;
		int leftchild = 2*index + 1;
		int rightchild = 2*index + 2;
		
		if((leftchild < length) && (arr[leftchild] > arr[parent]))
		{
			parent = leftchild;
		}
		
		if((rightchild < length) && (arr[rightchild] > arr[parent]))
		{
			parent = rightchild;
		}
		
		if(index != parent)
		{
			int temp = arr[index];
			arr[index] = arr[parent];
			arr[parent] = temp;
			
			heapify(arr, length, parent);
		}
	}
	
	void display()
	{
		for(int i = 0; i < arr.length; i++)
		{
			System.out.print(arr[i]+" ");
		}
		System.out.println();
	}
}


public class Assignment9 {
	public static void main(String args[])
	{
		Scanner sobj = new Scanner(System.in);
		
		System.out.println("Enter number elements : ");
		int size = sobj.nextInt();
		
		Heap_sort obj = new Heap_sort(size);
		obj.accept();
		
		System.out.println("Array Before sorting : ");
		obj.display();
		
		obj.sort();
		
		System.out.println("Array after sorting : ");	
		obj.display();
		
		sobj.close();
	}
}
