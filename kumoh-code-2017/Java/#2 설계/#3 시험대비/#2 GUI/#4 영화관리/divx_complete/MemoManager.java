import java.io.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class MemoManager extends JDialog
{
	private JPanel jp;
	private JTextArea memoArea;
	private JButton memoSave, memoLoad, memoExit;
	private JScrollPane scrollPane;
	private JFileChooser ch; //���̾�α׹ڽ� ����
	
	MemoManager()
	{
		setTitle("�޸�");
		setSize(330,330);
		setLocation(300,300);
		
		Font f = new Font("Dialog",Font.PLAIN,12);
		
		addWindowListener(new WindowAdapter ()
		{ public void windowClosing(WindowEvent we)
		{ setVisible(false); 
		}});
		
		JPanel jp = new JPanel();
		
		ch = new JFileChooser();
		File ff = new File("."); //���� ������ �ִ� ����Ʈ ���丮�� ��Ÿ����
		File fff = new File(""); // ���丮���� ����Ʈ���� ����
        	ch.setCurrentDirectory(ff);
		
		memoArea = new JTextArea(10,50); //�޸𿡾�� ũ�⼳��
		memoArea.setLineWrap(true);
		scrollPane = new JScrollPane(memoArea); //�޸𿡾� ��ũ�� �����
		getContentPane().add(scrollPane,"Center"); // �����ӿ� �޸𿡾��ڽ� ���̱�
                memoArea.setLineWrap(true); // ��ũ�� ���θ� �����ϰ��ϰ�
		scrollPane.validate(); // �ڵ����� �ٹٲ޵ǰ� �ϱ�
                memoArea.setFont(f); // �޸𿡾�� �۾� ����
		memoArea.setBackground(Color.orange);
		
		memoLoad = new JButton("�޸�ҷ�����");
		memoLoad.setFont(f);
		memoLoad.addActionListener(new LoadHandler()); 
		jp.add(memoLoad);
		
		memoSave = new JButton("�޸������ϱ�");
		memoSave.setFont(f);
		memoSave.addActionListener(new SaveHandler()); 
		jp.add(memoSave);
		
		memoExit = new JButton("������");
		memoExit.setFont(f);
		memoExit.addActionListener(new ExitHandler()); 
		jp.add(memoExit);
		
		getContentPane().add(jp, "South"); 
	}
	class LoadHandler implements ActionListener
	{
		public void actionPerformed(ActionEvent e)
		{
			if(ch.showOpenDialog(MemoManager.this)==ch.APPROVE_OPTION)
			{
				File file = ch.getSelectedFile();
				try
				{
					FileReader fr = new FileReader(file);
                    BufferedReader br = new BufferedReader(fr);
                                                                        				    
				    String aleadyLine = "";
				    String line = "";
				    while((line=br.readLine()) != null)
				    {
						aleadyLine += line+"\n";
				    }
				    memoArea.setText(aleadyLine);
				    br.close();
				    fr.close();                                                                    
				}
				catch(FileNotFoundException ee)
				{}catch(IOException eee){}
			}
		}
	}
	class SaveHandler implements ActionListener
    {
		public void actionPerformed(ActionEvent e)
       	{
			if(ch.showSaveDialog(MemoManager.this) == ch.APPROVE_OPTION)
			{
				File file = ch.getSelectedFile();
				try
				{
					String aleadyLine = " ";
     	      	    aleadyLine = memoArea.getText();
 
       	      	    FileWriter fw = new FileWriter(file);
       	      	    BufferedWriter bw = new BufferedWriter(fw);
       	      	    bw.write(aleadyLine);
       	      	    bw.close();                                                 
       	      	}catch(FileNotFoundException ee)
				{}catch(IOException eee){}
			}
		}
	}		
	class ExitHandler implements ActionListener
	{
		public void actionPerformed(ActionEvent e)
		{
			setVisible(false); 
		}
	}
}
