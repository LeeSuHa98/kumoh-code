import java.util.Vector;
import java.io.*;
import java.util.*;
import javax.swing.*;

class TableData extends Vector
{
	TableData()
	{}
	public TableData(String title, String cd, String codec, String genre, String grade)
	{
		add(title);
		add(cd);
		add(codec);
		add(genre);
		add(grade);
	}
	public static Vector getColName()
	{
		Vector colName = new Vector();
		colName.add("영화제목");
		colName.add("CD");
		colName.add("확장자");
		colName.add("장르");
		colName.add("평점");

		return colName;
	}
}

class DetailData extends Vector
{
	DetailData()
	{}
	public DetailData(String story) // 삭제해도 됨. 이전에 저장한 list.db 형식과 다르기때문에 남겨뒀음.
	{
		add(story);
	}
	public static Vector getStory()
	{
		Vector movieStory = new Vector();
		movieStory.add("Story");

		return movieStory;
	}
}

class Data implements Serializable
{
	private Vector tableData;
	private DetailData detailData;

	Data()
	{
		tableData = new Vector();
		detailData = new DetailData();
	}
	public void setTableData(TableData td) // 삭제해도 됨. 이전에 저장한 list.db 형식과 다르기때문에 남겨뒀음.
	{
		tableData.add(td);
	}
	public void setDetailData(String s)  // 삭제해도 됨. 이전에 저장한 list.db 형식과 다르기때문에 남겨뒀음.
	{
		detailData.add(s);
	}
	public Vector getTableData()
	{
		return tableData;
	}
	public Vector getDetailData()
	{
		return detailData;
	}
}

class TableManager extends JDialog
{
	private Data data;
	private Vector tableData;
	private Vector detailData;
	private String count;
	private String path;
	private JFileChooser chooser;
	private JFileFilter filter; 
	private File file ;

	TableManager()
	{
		data = new Data();
		tableData = data.getTableData();
		detailData = data.getDetailData();

		file = new File(".");
		chooser = new JFileChooser(file);

		filter = new JFileFilter();
		filter.addType("db");
		filter.addType("dat");
		filter.setDescription("Save Data (*.db , *.dat )");
		
		chooser.addChoosableFileFilter(filter);
	}
	public void save()
	{
		if(chooser.showSaveDialog(TableManager.this) == chooser.APPROVE_OPTION)
		{
			File f = chooser.getSelectedFile();
			path = f.getName();

			if(f.exists())
			{
				int option = JOptionPane.showConfirmDialog(new JFrame(), "같은 이름에 파일이존재합니다. 확~ 덮어 쒸울까요?","잠깐 !",JOptionPane.YES_NO_OPTION);
				if ( option == JOptionPane.NO_OPTION)
				{
					return;
				}
			}

			try
			{
				ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream(f));
    			oos.writeObject(data);
	    		oos.close();
    		}
	    	catch(Exception e)
    		{
    			System.out.println("Not Saveed -.-");
    		}
		}
	}
	public void load()
	{
		if(chooser.showOpenDialog(TableManager.this) == chooser.APPROVE_OPTION)
		{
			File f = chooser.getSelectedFile();
			path = f.getName();

			try
			{
				ObjectInputStream ois = new ObjectInputStream(new FileInputStream(f));
    			data = (Data)ois.readObject();
                tableData = data.getTableData();
	        	detailData = data.getDetailData();
                ois.close();
	    	}
    		catch(Exception e)
	    	{
				JOptionPane.showMessageDialog(this, " 저장방식이 다른 파일입니다." );
	    	}
		}
	}
	public String getTitleName()
	{
		return path;
	}
	// 내용 입력
	public void addTableData(TableData td)
	{
		tableData.add(td);
	}
	public void addDetailData(String s)
	{
		detailData.add(s);
	}
	// 선택한 내용 삭제
	public void delete(int select[])
	{
		int x = 0;

		for(int i=0; i<select.length ; i++)
		{
			tableData.remove((select[i] - x));
			detailData.remove((select[i] - x));
			x++;
		}
	}
	//영화 정보 수정
	public void modifyDetailData(String s , int index)
	{
		detailData.setElementAt(s , index);
	}
	// 벡터에 저장된 컴포넌트 개수 리턴
	public String getTableCount()
	{
		count = Integer.toString(tableData.size());
		return count;
	}
	// 내용 리턴
	public Vector getTableData()
	{
		return tableData;
	}
	public Vector getDetailData()
	{
		return detailData;
	}
	// 스토리 내용 리턴
	public String getStory(int rowNum)
	{
		return (String)detailData.get(rowNum);
	}
	// 새파일 ( 벡터내용 전체를 삭제 )
	public boolean delAll()
	{
		tableData.removeAllElements();
		detailData.removeAllElements();
		if(tableData.size() == 0 && detailData.size() == 0)
		{
			return true;
		}else
		{
			return false;
		}
	}
}

