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
	private JFileChooser ch; //다이얼로그박스 변수
	
	MemoManager()
	{
		setTitle("메모");
		setSize(330,330);
		setLocation(300,300);
		
		Font f = new Font("Dialog",Font.PLAIN,12);
		
		addWindowListener(new WindowAdapter ()
		{ public void windowClosing(WindowEvent we)
		{ setVisible(false); 
		}});
		
		JPanel jp = new JPanel();
		
		ch = new JFileChooser();
		File ff = new File("."); //현재 파일이 있는 디폴트 디렉토리가 나타나게
		File fff = new File(""); // 디렉토리에서 디폴트파일 설정
        	ch.setCurrentDirectory(ff);
		
		memoArea = new JTextArea(10,50); //메모에어리어 크기설정
		memoArea.setLineWrap(true);
		scrollPane = new JScrollPane(memoArea); //메모에어리어에 스크롤 만들기
		getContentPane().add(scrollPane,"Center"); // 프레임에 메모에어리어박스 붙이기
                memoArea.setLineWrap(true); // 스크롤 새로만 가능하게하고
		scrollPane.validate(); // 자동으로 줄바꿈되게 하기
                memoArea.setFont(f); // 메모에어리어 글씨 설정
		memoArea.setBackground(Color.orange);
		
		memoLoad = new JButton("메모불러오기");
		memoLoad.setFont(f);
		memoLoad.addActionListener(new LoadHandler()); 
		jp.add(memoLoad);
		
		memoSave = new JButton("메모저장하기");
		memoSave.setFont(f);
		memoSave.addActionListener(new SaveHandler()); 
		jp.add(memoSave);
		
		memoExit = new JButton("나가기");
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
