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
		colName.add("��ȭ����");
		colName.add("CD");
		colName.add("Ȯ����");
		colName.add("�帣");
		colName.add("����");

		return colName;
	}
}

class DetailData extends Vector
{
	DetailData()
	{}
	public DetailData(String story) // �����ص� ��. ������ ������ list.db ���İ� �ٸ��⶧���� ���ܵ���.
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
	public void setTableData(TableData td) // �����ص� ��. ������ ������ list.db ���İ� �ٸ��⶧���� ���ܵ���.
	{
		tableData.add(td);
	}
	public void setDetailData(String s)  // �����ص� ��. ������ ������ list.db ���İ� �ٸ��⶧���� ���ܵ���.
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
				int option = JOptionPane.showConfirmDialog(new JFrame(), "���� �̸��� �����������մϴ�. Ȯ~ ���� ������?","��� !",JOptionPane.YES_NO_OPTION);
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
				JOptionPane.showMessageDialog(this, " �������� �ٸ� �����Դϴ�." );
	    	}
		}
	}
	public String getTitleName()
	{
		return path;
	}
	// ���� �Է�
	public void addTableData(TableData td)
	{
		tableData.add(td);
	}
	public void addDetailData(String s)
	{
		detailData.add(s);
	}
	// ������ ���� ����
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
	//��ȭ ���� ����
	public void modifyDetailData(String s , int index)
	{
		detailData.setElementAt(s , index);
	}
	// ���Ϳ� ����� ������Ʈ ���� ����
	public String getTableCount()
	{
		count = Integer.toString(tableData.size());
		return count;
	}
	// ���� ����
	public Vector getTableData()
	{
		return tableData;
	}
	public Vector getDetailData()
	{
		return detailData;
	}
	// ���丮 ���� ����
	public String getStory(int rowNum)
	{
		return (String)detailData.get(rowNum);
	}
	// ������ ( ���ͳ��� ��ü�� ���� )
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

