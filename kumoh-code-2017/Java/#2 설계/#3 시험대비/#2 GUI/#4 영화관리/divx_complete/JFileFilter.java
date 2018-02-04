import java.io.File;
import java.util.*;

class JFileFilter extends javax.swing.filechooser.FileFilter 
{
	private String description;
	private ArrayList filterList = new ArrayList();

	public void addType(String s)
	{
		filterList.add(s);
	}

	public boolean accept(File f)
	{
		if(f.isDirectory())
		{
			return true;
		}else if(f.isFile())
		{
			Iterator it = filterList.iterator();
			while(it.hasNext())
			{
				if(f.getName().endsWith((String)it.next()))
					return true;
			}
		}
		return false;
	}

	public void setDescription(String s)
	{
		description = s;
	}

	public String getDescription()
	{
		return description;
	}
}