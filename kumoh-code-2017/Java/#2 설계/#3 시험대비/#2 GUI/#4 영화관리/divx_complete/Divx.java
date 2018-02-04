import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.event.*;
import javax.swing.table.*;
import java.io.*;
import java.util.*;


public class Divx extends JFrame implements ActionListener, TableModelListener
{
	private JScrollPane jp;
	private JTable table;
	private JPanel panel;
	private JMenuBar menubar;
	private JMenu menu, sortMenu;
	private JMenuItem newItem, loadItem, saveItem, exitButtonItem, sortName, sortGenre, memoItem, verItem, helpItem;
	private JButton inputButton,delButton,infoButton,findButton,exitButton;
	private JLabel orderLabel, orderLabel2;
	private DefaultTableModel model = null;
	private Font f;
	private File file;
	private boolean state = true; // ������� Ȯ��. �������� �ʾƵ� �Ǵ»��� ���� = false
	private boolean infoState = true; // true �� ��ȭ����.
	private int xLocation;
	private int yLocation;
	private int sortInt = 0;

	private JFileFilter filter = new JFileFilter();

	private TableManager tm = new TableManager();
	private TableData td = new TableData();
	private MemoManager mm = new MemoManager();
	private InputManager im = new InputManager(this);
	private InfoMovie in = new InfoMovie();
	private FindManager fm = new FindManager();

	Divx()
	{
		addWindowListener(new WindowAdapter()
		{
			public void windowClosing(WindowEvent we)
			{
				exit();
			}
		});

		// ó�� ����� size.txt������ �о ���� ����� ��ġ�� �а� �� ��ġ�� x,y��ǥ�� �����.
		try
		{
			file = new File("size.txt");
			
			String temp = "";
			String i[] = new String[2];
			int count=0;
			
			BufferedReader br = new BufferedReader(new FileReader(file));
						
			while((temp = br.readLine()) != null )
			{
				i[count] = temp;
				count++;
			}

			xLocation = Integer.parseInt(i[0]);
			yLocation = Integer.parseInt(i[1]);

    		br.close();
		}
		catch(NumberFormatException e)
		{
			System.out.println(e);
		}
		catch(IOException ee) // ó�� ����� ������ ���� ���ܰ� �߻�. ���ܹ߻��� �� ũ��,��ġ �� ����.
		{
			xLocation = 150;
			yLocation = 150;
		}


		super.setTitle("CoJ_Divx_Manager v1.0");
		setIconImage(new ImageIcon("coj.gif").getImage());
		setSize(380,515);
		setLocation(xLocation , yLocation);

		f = new Font("Dialog",Font.PLAIN,12);  //��Ʈ ����

		Container contentPane = getContentPane();
		contentPane.setLayout(new BorderLayout());

		//�޴������
		menubar = new JMenuBar();
		setJMenuBar(menubar);

		menu = new JMenu("����");
		menubar.add(menu);
		menu.setFont(f);
		newItem = new JMenuItem("������", new ImageIcon("new.gif"));
		newItem.addActionListener(this);
		menu.add(newItem);
		loadItem = new JMenuItem("�ҷ�����", new ImageIcon("open.gif"));
		menu.add(loadItem);
		loadItem.addActionListener(this);
		saveItem = new JMenuItem("�����ϱ�", new ImageIcon("save.gif"));
		menu.add(saveItem);
		saveItem.addActionListener(this);
		menu.addSeparator();
		menu.addSeparator();
		exitButtonItem = new JMenuItem("����", new ImageIcon("exit.gif"));
		menu.add(exitButtonItem);
		exitButtonItem.addActionListener(this);

		menu = new JMenu("����");
		menubar.add(menu);
		menu.setFont(f);
		sortMenu = new JMenu("����");
		sortMenu.setFont(f);
		sortName = new JMenuItem("��ȭ����");
		sortMenu.add(sortName);
		sortName.addActionListener(this);
		sortGenre = new JMenuItem("�� ��");
		sortMenu.add(sortGenre);
		sortGenre.addActionListener(this);
		menu.add(sortMenu);
		memoItem = new JMenuItem("�޸�");
		menu.add(memoItem);
		memoItem.addActionListener(this);


		menu = new JMenu("����");
		menubar.add(menu);
		menu.setFont(f);
		verItem = new JMenuItem("����");
		menu.add(verItem);
		verItem.addActionListener(this);
		helpItem = new JMenuItem("����");
		menu.add(helpItem);
		helpItem.addActionListener(this);

		newItem.setFont(f); loadItem.setFont(f); saveItem.setFont(f); exitButtonItem.setFont(f);
		verItem.setFont(f); helpItem.setFont(f);
		sortName.setFont(f); sortGenre.setFont(f); memoItem.setFont(f);

		orderLabel = new JLabel("  ��ȭ ���� : ");
		orderLabel.setFont(f);
		menubar.add(Box.createHorizontalGlue());
		menubar.add(orderLabel);

		orderLabel2 = new JLabel(" 0 "); // ���� ��ȭ �� ���� ǥ��
		orderLabel2.setFont(f);
		menubar.add(orderLabel2);

		panel = new JPanel();
		panel.setLayout(new FlowLayout());
		//��ư �����
        inputButton = new JButton( new ImageIcon("in.gif"));
        inputButton.setSize(70,30);
		panel.add(inputButton);
        inputButton.addActionListener(this);
		inputButton.setToolTipText("�Է� �ϱ�");

        delButton = new JButton( new ImageIcon("del.gif"));
        delButton.setSize(70,30);
        panel.add(delButton);
		delButton.addActionListener(this);
		delButton.setToolTipText("���� �ϱ�");

        infoButton = new JButton( new ImageIcon("information.gif"));
        infoButton.setSize(90,30);
		panel.add(infoButton);
		infoButton.addActionListener(this);
		infoButton.setToolTipText("��ȭ ����");

		findButton = new JButton( new ImageIcon("search.gif"));
		findButton.setSize(70,30);
		panel.add(findButton);
        findButton.addActionListener(this);
		findButton.setToolTipText("��ȭ ã��");

		exitButton = new JButton( new ImageIcon("exit1.gif"));
		exitButton.setSize(70,30);
        panel.add(exitButton);
		exitButton.addActionListener(this);
		exitButton.setToolTipText("����");

		model = new DefaultTableModel(td.getColName() , 0); //tm.getTableData() , new TableData().getColName()); //td.getKeys());
		model.addTableModelListener(this);
		table = new JTable(model);
		table.setSelectionMode(ListSelectionModel.MULTIPLE_INTERVAL_SELECTION); //SINGLE_SELECTION);
		table.setSelectionBackground(Color.orange);
		table.setGridColor(Color.black);
		table.setEditingColumn(0); 

		im.setModel();
		jp = new JScrollPane(table);
		contentPane.add(jp);
		contentPane.add(panel,"South");

	  	//�۾�ü ����
		infoButton.setFont(f); findButton.setFont(f); inputButton.setFont(f); delButton.setFont(f); exitButton.setFont(f);
	}
	public void getSizeLocation()  // ����Ǳ����� �� ũ��,��ġ ���� �����Ѵ�.
	{
   		String px = String.valueOf(getX());
    	String py = String.valueOf(getY());
		try
		{
			BufferedWriter bw = new BufferedWriter(new FileWriter("size.txt"));

			bw.write(px + "\n");
			bw.write(py);

			bw.close();
		}
		catch(IOException eee)
		{
			System.out.println(eee);
		}
	}
	public void tableChanged(TableModelEvent tme)
	{
		state = false;
	}
    public void actionPerformed(ActionEvent ae)
	{
		Object o = ae.getSource();

		if(o == inputButton) //�Է�
		{
			input();
        }
        else if(o == delButton) //����
        {
			int delCount[] = table.getSelectedRows(); // ������ row���� �迭�� ���� (���� ������ ���� �迭 ���)
			if(delCount.length == 0)
			{
				JOptionPane.showMessageDialog(this,"������ �����͸� �����ϼ���");
				return;
			}
			int q = JOptionPane.showConfirmDialog(this,delCount.length + " ���� �����͸� �����Ͻðڽ��ϱ� ? ", "����",JOptionPane.YES_NO_OPTION);
			if(q == JOptionPane.YES_OPTION)
			{
				tm.delete(delCount);
				model.setDataVector(tm.getTableData(), TableData.getColName());
				orderLabel2.setText(tm.getTableCount()); // ���� ���̺� �ִ� ������ ���� ǥ��
				
				im.setModel(); // ���̺� Ÿ�̺�� ������ �ٽ� ����
				state = false; // �����ؾߵ�
			}
        }
		else if(o == infoButton) // ��ȭ����
		{
			int rowNum = table.getSelectedRow();
			if(rowNum == -1)
			{
				JOptionPane.showMessageDialog(this,"���õ� �����Ͱ� �����ϴ�");
				return;
			}
			infoState = true;
			in.setArea(rowNum);
		}
        else if(o == findButton) // ã�� (��ȭ�������� ã��)
        {
			if(tm.getTableData().size() == 0) 
			{
				JOptionPane.showMessageDialog(this,"ã�� ����Ÿ�� �����ϴ�.");
				return;
			}

			fm.setVisible(true);
      }
		else if(o == exitButton) // ����
		{
			exit();
		}
		else if(o == newItem) // ���ο� ����
		{
			if(!state)
			{
				int i= JOptionPane.showConfirmDialog(this,"�������� �������� ���� �Ͻ÷��ϱ�?","«��",JOptionPane.YES_NO_OPTION);
				if(i == JOptionPane.YES_OPTION)
				{
					tm.save();
					state = true;
				}
			}

			boolean delState = tm.delAll(); // ����� ���������� true�� �����Ѵ�.
			if(delState)
			{
				model.setDataVector(tm.getTableData(), td.getColName());
    			orderLabel2.setText(tm.getTableCount());
				setTitle("Divx_Manager v1.0");
				state = true;
				return;
			}
			JOptionPane.showMessageDialog(this,"������ ���������� �������� �ʾҽ��ϴ�.");
		}
		else if(o == loadItem) // ����� ���� �ҷ�����
		{
			if(!state)
			{
				int i = JOptionPane.showConfirmDialog(this,"�ҷ��������� ������ �Ͻ÷ƴϱ�?","���",JOptionPane.YES_NO_OPTION);
				if(i == JOptionPane.YES_OPTION)
				{
					tm.save();
				}
			}

			tm.load();
			setTitle("Divx_Manager v1.0 - " + (tm.getTitleName())); //
			model.setDataVector(tm.getTableData(), td.getColName());
			orderLabel2.setText(tm.getTableCount());
			state = true;

			im.setModel();
		}
		else if(o == saveItem)
		{
			tm.save();
			setTitle("Divx_Manager v1.0 - " + (tm.getTitleName())); //
			state = true; // ������ص� ��
		}
		else if(o == exitButtonItem) // ����
		{
			exit();
		}
		else if(o == sortName) // ��ȭ�������� ����
		{
			sortInt = 1;
			sort();
		}
		else if(o == sortGenre)
		{
			sortInt = 2;
			sort();
		}
		else if(o == memoItem) // ������ �޸���
		{
			mm.show();
		}
		else if( o == verItem) // ����
		{
			StringBuffer sb = new StringBuffer();

			sb.append(" �� Ī : Divx_Manager_Ver 1.0");
			sb.append("\n");
			sb.append(" �� �� : ��ȭCD ���� ���α׷�");
			sb.append("\n");
			sb.append(" ȯ �� : J2SDK1.4 , Window2000Pro , EditPlus");
			sb.append("\n");
			sb.append(" ī �� : http://cafe.daum.net/comeonjava");
			sb.append("\n");
			sb.append(" �� �� : �����̶� ������ �����ɸ� ^^;;");
			sb.append("\n");

			JOptionPane.showMessageDialog(this,sb.toString());
		}
		else if(o == helpItem) // ����
		{
			infoState = false;
			in.helpView();
		}
	}
	public void input()
	{
		im.show();
	}
	public void exit()
	{
		if(!state)
		{
			int i = JOptionPane.showConfirmDialog(this,"�����ϱ����� ������ �Ͻ÷ƴϱ�?","���",JOptionPane.YES_NO_OPTION);
			if(i == JOptionPane.YES_OPTION)
			{
				tm.save();
    			getSizeLocation();
				System.exit(0);
			}
		}
		getSizeLocation();
		System.exit(0);
	}
	public static void main(String[] args)
	{
//		try{
//			UIManager.setLookAndFeel("com.sun.java.swing.plaf.windows.WindowsLookAndFeel");
//		}catch(Exception ex){}
		
		JFrame jf = new Divx();
		jf.show();
	}
//---------------------------------------------------------------------------------------------------
//---------------------------- S o r t M a n a g e r      C l a s s ---------------------------------
//---------------------------------------------------------------------------------------------------
	public void sort()
	{
		if(table.getRowCount() == 0)
			return;

		String sortName1 = null;
		String sortCd1 = null;
		String sortCodec1 = null;
		String sortGenre1 = null;
		String sortGrade1 = null;
		String sortStory1 = null;

		String sortName2 = null;
		String sortGenre2 = null;
		String sortStory2 = null;

		switch(sortInt)
		{
			case 1:
				for(int s=0; s < table.getRowCount() ; s++)
				{
					for(int ss=0; ss < table.getRowCount()-1 -s; ss++)
					{
						sortName1 = (String)table.getValueAt(ss,0);
						sortName2 = (String)table.getValueAt(ss+1,0);

						if(sortName1.compareTo(sortName2) > 0)
						{
							sortCd1 = (String)table.getValueAt(ss,1);
							sortCodec1 = (String)table.getValueAt(ss,2);
							sortGenre1 = (String)table.getValueAt(ss,3);
							sortGrade1 = (String)table.getValueAt(ss,4);
							sortStory1 = tm.getStory(ss);

							table.setValueAt(sortName2,ss,0);
							table.setValueAt((String)table.getValueAt(ss+1,1),ss,1);
							table.setValueAt((String)table.getValueAt(ss+1,2),ss,2);
							table.setValueAt((String)table.getValueAt(ss+1,3),ss,3);
							table.setValueAt((String)table.getValueAt(ss+1,4),ss,4);
							tm.modifyDetailData(tm.getStory(ss+1),ss);

							table.setValueAt(sortName1,ss+1,0);
							table.setValueAt(sortCd1,ss+1,1);
							table.setValueAt(sortCodec1,ss+1,2);
							table.setValueAt(sortGenre1,ss+1,3);
							table.setValueAt(sortGrade1,ss+1,4);
							tm.modifyDetailData(sortStory1,ss+1);
						}
					}
				}
				sortName1 = null;
				sortCd1 = null;
				sortCodec1 = null;
				sortGenre1 = null;
				sortGrade1 = null;
				sortStory1 = null;

				sortName2 = null;
	
				model.setDataVector(tm.getTableData(), this.td.getColName());
   				im.setModel();
				break;
			
			case 2:
				for(int s=0; s < table.getRowCount(); s++)
				{
					for(int ss=0; ss < table.getRowCount()-1 -s; ss++)
					{
						sortGenre1 = (String)table.getValueAt(ss,3);
						sortGenre2 = (String)table.getValueAt(ss+1,3);
						
						if(sortGenre1.compareTo(sortGenre2) > 0 )
						{
							sortName1 = (String)table.getValueAt(ss,0);
							sortCd1 = (String)table.getValueAt(ss,1);
							sortCodec1 = (String)table.getValueAt(ss,2);
							sortGrade1 = (String)table.getValueAt(ss,4);
							sortStory1 = tm.getStory(ss);

							table.setValueAt((String)table.getValueAt(ss+1,0),ss,0);
							table.setValueAt((String)table.getValueAt(ss+1,1),ss,1);
							table.setValueAt((String)table.getValueAt(ss+1,2),ss,2);
							table.setValueAt(sortGenre2,ss,3);
							table.setValueAt((String)table.getValueAt(ss+1,4),ss,4);
							tm.modifyDetailData(tm.getStory(ss+1),ss);

							table.setValueAt(sortName1,ss+1,0);
							table.setValueAt(sortCd1,ss+1,1);
							table.setValueAt(sortCodec1,ss+1,2);
							table.setValueAt(sortGenre1,ss+1,3);
							table.setValueAt(sortGrade1,ss+1,4);
							tm.modifyDetailData(sortStory1,ss+1);
						}
					}
				}
				sortName1 = null;
				sortCd1 = null;
				sortCodec1 = null;
				sortGenre1 = null;
				sortGrade1 = null;
				sortStory1 = null;

				sortGenre2 = null;

				model.setDataVector(tm.getTableData(), this.td.getColName());
				im.setModel();
				break;
		}
	}


//---------------------------------------------------------------------------------------------------
//---------------------------- F i n d M a n a g e r      C l a s s ---------------------------------
//---------------------------------------------------------------------------------------------------
	class FindManager extends JDialog
	{
		private JPanel panel;
		private JLabel inputLabel;
		private JTextField inputField;
		private JButton okButton, noButton, backButton;
		private String str;
		private String findM;
		int i=0;
		int ii=0;
		int j=0;
		int jj=0;
		private boolean boo = true;

		public FindManager()
		{
			setTitle("��ȭ ã��");
			panel = new JPanel();
			inputLabel = new JLabel(" * ã�� ��ȭ ������ �Է��ϼ��� *",SwingConstants.CENTER);
			inputLabel.setFont(f);
			inputField = new JTextField();
			okButton = new JButton("ã��(����)");
			okButton.setFont(f);

			okButton.addActionListener(new ActionListener()
			{
				public void actionPerformed(ActionEvent ae)
				{
					if(!boo) i= ++jj;
					str = inputField.getText();

					if(str.equals(""))
					{
						return;
					}
					else
					{
						JViewport viewport = jp.getViewport();
						for(; i < table.getRowCount(); i++)
						{
							findM = (String)table.getValueAt(i,0);

							if(findM.indexOf(str) >= 0)
							{
								table.setRowSelectionInterval(i,i); 

								if (!viewport.getViewRect().contains(10, i*table.getRowHeight()))
								{
									
									viewport.setViewPosition(new Point(0,i*table.getRowHeight()));
									
								}
								ii = i; // ���������� ���õ� row���� �����Ѵ�.
								i++;
								boo = true; 						
								return;
							}
						}
						i=ii;
					}
					JOptionPane.showMessageDialog(new JFrame(),"ã�� ��ȭ������ �����ϴ�");
				}						
			});

			backButton = new JButton("�ڷ�");
			backButton.setFont(f);
			backButton.addActionListener(new ActionListener()
			{
				public void actionPerformed(ActionEvent ae)
				{
					if(boo) i= ii;
					str = inputField.getText();
					
					if(str.equals(""))
					{
						return;
					}
					else
					{
						JViewport viewport = jp.getViewport();
						for(; j < i ; j++)
						{
							findM = (String)table.getValueAt(j,0);

							if(findM.indexOf(str) >= 0)
							{
								table.setRowSelectionInterval(j,j);
								if (!viewport.getViewRect().contains(10, j*table.getRowHeight()))
								{
									viewport.setViewPosition(new Point(0, j*table.getRowHeight()));
								}
								jj = j;
								boo = false;
							}
						}
						i=jj;
						j=0; // ó������ (i��-1)���� �˻��ϱ����� j���� 0���� �������.
					}
				}
			});

			noButton = new JButton("���");
			noButton.setFont(f);
			noButton.addActionListener(new ActionListener()
			{
				public void actionPerformed(ActionEvent ae)
				{
					inputField.setText("");
					int i=0;
					int ii=0;
					int j=0;
					int jj=0;
					boo = true;

					setVisible(false);
				}
			});

			panel.add(okButton);
			panel.add(backButton);
			panel.add(noButton);

			getContentPane().add(inputLabel,"North");
			getContentPane().add(inputField,"Center");
			getContentPane().add(panel,"South");

			setSize(300,110); 
			setLocation(200,200);
			setResizable(false);
		}
	}
//-----------------------------------------------------------------------------------------------------
// ----------------------------   I n p u t M a n a g e r        C l a s s ----------------------------
//-----------------------------------------------------------------------------------------------------

    class InputManager extends JDialog implements ActionListener
	{
		private JLabel movieName, movieStory;
    	private JPanel jp1,jp2;
    	private JTextArea story;
    	private JButton ok,off;
    	private JTextField name;
    	private JComboBox number,codec,genre,grade;
    	private JScrollPane scroll;

    	private TableData td; 
    	private DetailData dd;

    	public InputManager(JFrame frame)
    	{
    		super(frame,"��ȭ �Է�",true);

    		Font font = new Font("Dialog", Font.PLAIN,11);

    		addWindowListener(new WindowAdapter()
	    	{
		    	public void windowClosing(WindowEvent we)
    			{
	    			setVisible(false);
		    	}
    		});

			number = new JComboBox();
    		number.setEditable(true);
	    	number.addItem("��ȭ���"); number.addItem("1"); number.addItem("2"); number.addItem("3"); number.addItem("4"); number.addItem("5");
    		number.setFont(font);

    		codec = new JComboBox();
	    	codec.setEditable(true);
    		codec.addItem("Ȯ����"); codec.addItem("AVI");  codec.addItem("PDIVX"); codec.addItem("MPEG"); codec.addItem("RM"); codec.addItem("ASF"); codec.addItem("ASX");
	    	codec.setFont(font);

    		genre = new JComboBox();
	    	genre.setEditable(true);
    		genre.addItem("�帣"); genre.addItem("�׼�"); genre.addItem("������"); genre.addItem("�ڹ�"); genre.addItem("���"); genre.addItem("���"); genre.addItem("����");
	    	genre.addItem("����"); genre.addItem("������"); genre.addItem("SF"); genre.addItem("ȯŸ��"); genre.addItem("���ϸ��̼�"); genre.addItem("3D");
    		genre.setFont(font);

    	   	grade = new JComboBox();
	    	grade.setEditable(true);
    		grade.addItem("����"); grade.addItem("1"); grade.addItem("2"); grade.addItem("3"); grade.addItem("4"); grade.addItem("5");
	    	grade.addItem("6"); grade.addItem("7"); grade.addItem("8"); grade.addItem("9"); grade.addItem("10");
    		grade.setFont(font);

    		movieName = new JLabel("��ȭ ����");
	    	movieName.setFont(font);

    		name = new JTextField("",20);
	    	name.setFont(font);

    		movieStory = new JLabel(" :: ��ȭ ���� & �ٰŸ� ::");
	    	movieStory.setFont(font);

    		story = new JTextArea("",10,20);
	    	scroll = new JScrollPane(story);
    		story.setBackground(Color.orange);

    		ok = new JButton("�Է�");
	    	ok.setFont(font);
    		ok.addActionListener(this);

    		off = new JButton("����");
	    	off.setFont(font);
    		off.addActionListener(this);

    		jp1 = new JPanel();
	    	jp2 = new JPanel();

    		jp1.add(movieName);
	    	jp1.add(name);
    		jp2.add(number);
    		jp2.add(codec);
    		jp2.add(genre);
    		jp2.add(grade);
     		jp2.add(movieStory);
    		jp2.add(scroll);
    		jp2.add(ok);
    		jp2.add(off);

    		getContentPane().add(jp1,"North");
    		getContentPane().add(jp2,"Center");

    		setTitle("�Է�");
	    	setSize(230,360);
    		setLocation(200,200);
	    	setResizable(false);
		}
		public void actionPerformed(ActionEvent e)
    	{
	    	if(e.getSource().equals(ok))
    		{
	    		ok();
    		}
	    	else if(e.getSource().equals(off))
	    	{
	    		setVisible(false);
	    	}
    	}
    	public void ok()  // ���ο� ���� �Է� (Ȯ��)
    	{
    		td = new TableData(name.getText(),(String)number.getSelectedItem(),(String)codec.getSelectedItem(),(String)genre.getSelectedItem(),(String)grade.getSelectedItem());

    		tm.addTableData(td);
    		tm.addDetailData(story.getText());

    		orderLabel2.setText(tm.getTableCount()); // ���� ��ȭ ������ ǥ��

			state = false;

	    	name.setText("");
    		story.setText("");

    		model.setDataVector(tm.getTableData(), this.td.getColName());
    		setModel();
    	}
    	public void setModel() // ���̺� Ÿ��Ʋ ���� ����.
    	{
    	    TableColumn column = null;
    	    for(int i=0; i<table.getColumnCount(); i++)
    		{
    			column = table.getColumnModel().getColumn(i);

    			if(i == 0)
    			{
    				column.setPreferredWidth(150);
    			}else if(i == 1)
    			{
    				column.setPreferredWidth(10);
    			}else if(i == 2)
    			{
    				column.setPreferredWidth(30);
    			}else if(i == 3)
    			{
    				column.setPreferredWidth(70);
    			}else if(i == 4)
    			{
    				column.setPreferredWidth(20);
    			}else if(i == 5)
    			{
    				column.setPreferredWidth(10);
    		    }
    		}
    	}
    }
//------------------------------------------------------------------------------------------------
// -------------------------------- I n f o M o v i e   C l a s s --------------------------------
//------------------------------------------------------------------------------------------------
	class InfoMovie extends JDialog
	{
		private JTextArea area;
		private JButton ok;
		private String story;
		private int rowNum;

		InfoMovie()
		{
			area = new JTextArea();
			ok = new JButton("Ȯ��");
			ok.addActionListener(new ActionListener()
			{
				public void actionPerformed(ActionEvent ae)
				{
					if(!infoState)
					{
						area.setText("");
						setVisible(false);
					}
					else
					{
						tm.modifyDetailData(area.getText(), rowNum);
						area.setText("");
						setVisible(false);
					}
				}

			});

			area.setLineWrap(true);

			area.setFont(f);
			ok.setFont(f);

			area.setBackground(Color.orange);

			getContentPane().add(new JScrollPane(area),"Center");
			getContentPane().add(ok,"South");

			setLocation(200,200);
			setSize(300,300);
		}
		public void setArea(int rowNum) // ��ȭ����
		{
			this.rowNum = rowNum;

			setTitle(" �� ȭ �� �� ");
			try
			{
				this.story = tm.getStory(rowNum);
				area.setText(story);

				show();
			}catch(Exception e)
			{
				System.out.println(e.toString());
			}
		}
		public void helpView() // ����
		{
			setTitle(" �� �� �� ");

			area.append("                                     :::: ���� ���� :::: ");
			area.append("\n");
			area.append("\n");
			area.append(" * ������ ���� * ");
			area.append("\n");
			area.append(" ����� �����͸� ���� �� ���� �� �ȿ� �ִ� �����͸�  ");
			area.append("\n");
			area.append(" ������ �ݵ�� Enter�� �ٸ� ���� Ŭ���Ͽ� ���ȿ��� ");
			area.append("\n");
			area.append(" ���� �����ð� �����ϼ���.");
			area.append("\n");
			area.append("\n");
			
			show();
		}
	}
}
