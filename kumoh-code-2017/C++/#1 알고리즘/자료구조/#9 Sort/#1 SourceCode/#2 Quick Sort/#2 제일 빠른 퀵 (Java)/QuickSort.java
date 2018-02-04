import java.util.ArrayList;

public class QuickSort
{
	public QuickSort() {}
	
	private int medianOfThree(ArrayList<String> arr, int left, int right)
	{
		int mid;
		mid = (left + right) / 2;

		//      left, mid, right의 숫자들의 크기를 순서대로 정렬할 것이다.
		if (arr.get(left).compareTo(arr.get(mid)) == 1)//좌측과 중간값을 비교해서 정렬
		{
			//swap(arr.get(left), arr.get(mid));
			String temp = arr.get(left);
			arr.set(left,arr.get(mid));
			arr.set(mid,temp);
			
		}
		if (arr.get(left).compareTo(arr.get(right)) == 1)//기서 좌측을 우측값과 비교해서 정렬
		{
			//swap(arr[left], arr[right]);
			String temp = arr.get(left);
			arr.set(left,arr.get(right));
			arr.set(right,temp);
		}
		if (arr.get(mid).compareTo(arr.get(right)) == 1)//마지막으로 중간값과 우측값을 비교해서 정렬
		{
			//swap(arr[mid], arr[right]);
			String temp = arr.get(mid);
			arr.set(mid,arr.get(right));
			arr.set(right,temp);
		}

		return mid;
	}
	
	public void sort(ArrayList<String> arr, int left, int right)
	{
		if (left < right)
		{
			int i = left;
			int j = right + 1;
			String pivot;

			int median_mid = medianOfThree(arr, left, right);
			pivot = arr.get(median_mid);

			//arr[median_mid] = arr[left];
			arr.remove(median_mid);
			arr.add(median_mid, arr.get(left));
			//arr[left] = pivot;
			arr.remove(left);
			arr.add(left, pivot);
			
			do
			{
				do
				{
					i++;
					if (i >= j)
					{
						break;
					}
				} while (pivot.compareTo(arr.get(i)) == 1);
				do
				{
					j--;
					if (j <= 0)
					{
						break;
					}
				} while (arr.get(j).compareTo(pivot) == 1);
				if (i < j)
				{
					//swap(arr.get(i), arr.get(j));
					String temp = arr.get(i);
					arr.set(i,arr.get(j));
					arr.set(j,temp);
				}
			} while (i < j);

			//swap(arr[left], arr[j]);
			String temp = arr.get(left);
			arr.set(left,arr.get(j));
			arr.set(j,temp);
			
			sort(arr, left, j - 1);
			sort(arr, j + 1, right);
		}
	}
}
