import java.awt.Container;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.awt.event.KeyAdapter;
import java.awt.font.LineMetrics;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import javax.swing.JButton;
import javax.swing.JFileChooser;
import javax.swing.JFrame;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JPanel;
import javax.swing.JPopupMenu;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.JTextPane;
import javax.swing.text.DefaultCaret;
import javax.swing.text.StyledDocument;

public class NotePad extends JFrame implements ActionListener{

	JMenuBar mainBar;

	JMenu menuFile, menuEdit;

	JMenuItem newNote, openNote, saveNote, otherSaveNote, exit, find, fontEdit;

	JTextPane ta;
	
	JScrollPane sp, js1, js2;;
	
	JFileChooser file;

	FontChanged fc;

	StyledDocument sd;

	Container co;
	
	DefaultCaret cc;

	int start, leng, num;
	
	LineMetrics lm;
	
	JButton b1, b2;
	
	JPanel p1, p2;
	
	JTextArea ta1, ta2;
	
	Runtime r;
	
	String fileName;

	NotePad() {
		
		super("�޸���");																// Frame â Ÿ��Ʋ�� ����
		co = getContentPane();                                                 // Frame�� ���̱� ���� Container ��ü ����
		ta = new JTextPane();                                                   // ���õ� Text�� ��Ʈ ������ ���� TextPane ���
		sd = ta.getStyledDocument();                                        //  ���õ� Text�� ��Ʈ ������ StyleDocument ��ü ����
		sp = new JScrollPane(ta);
        
		/*
         * �޴��ٿ� �޴������� ��ü ���� 
         */
		mainBar = new JMenuBar();
		menuFile = new JMenu("����");
		menuEdit = new JMenu("����");
		find = new JMenuItem("ã��    (Ctrl+F)");
		fontEdit = new JMenuItem("����    (Ctrl+E)");
		newNote=new JMenuItem("���ξ���");
		openNote=new JMenuItem("����    (Ctrl+O)");
		saveNote=new JMenuItem("����    (Ctrl+S)");
		exit=new JMenuItem("������");
		file=new JFileChooser();
		
		/*
		 * �޴��ٿ� �޴��������� ���̰�
		 * �̺�Ʈ ������ ����
		 */
		menuFile.add(newNote);
		menuFile.add(openNote);
		menuFile.add(saveNote);
		menuFile.addSeparator();
		menuFile.add(exit);
		menuEdit.add(find);
		menuEdit.add(fontEdit);
		newNote.addActionListener(this);
		openNote.addActionListener(this);
		saveNote.addActionListener(this);
		exit.addActionListener(this);
		find.addActionListener(this);
		fontEdit.addActionListener(this);
		setJMenuBar(mainBar);
		mainBar.add(menuFile);
		mainBar.add(menuEdit);
		co.add(sp,"Center");
		setBounds(400, 200, 500, 400);
		setVisible(true);
		
		ta.addMouseListener(new MouseAdapter(){
			
			/*
			 * ta �� ���콺 �̺�Ʈ �߰�
			 * ���콺 ��Ŭ���� �˾�â ���
			 */
			public void mouseClicked(MouseEvent e) {
				if (e.getButton() == 3) {
					NotePop np = new NotePop(NotePad.this);
					np.show(e.getComponent(), e.getX(), e.getY());
				}
			}
		});

		addWindowListener(new WindowAdapter(){
			public void windowClosing(WindowEvent e) {
				System.exit(0);
			}
		});
		
		ta.addKeyListener(new KeyAdapter(){
			
			/*
			 * ����Ű ����
			 */
			public void keyReleased(KeyEvent e){
				
				/*
				 * Ctrl Ű�� ������ ���� ����
				 */
				if(e.isControlDown()){
					if(e.getKeyCode()==KeyEvent.VK_E){                      //Ctrl ������ ���¿��� E Ű�� ������ ��Ʈ���� ���̾�α�
						fontSelectCheck();
					}
					else if(e.getKeyCode()==KeyEvent.VK_F){              //Ctrl ������ ���¿��� F Ű�� ������ ã�� ���̾�α�
						new FindDialog(NotePad.this);
					}
					else if(e.getKeyCode()==KeyEvent.VK_O){              //Ctrl ������ ���¿��� O Ű�� ������ ã�� ���Ͽ���â 
						int i=file.showOpenDialog(NotePad.this);
						if(i==0)openAndsave(0);
					}
					else if(e.getKeyCode()==KeyEvent.VK_S){              //Ctrl ������ ���¿��� F Ű�� ������ ���� ���̾�α� ��
						int i=file.showSaveDialog(NotePad.this);
						if(i==0)openAndsave(1);
					}
				}

			}
		});
	}

	public void actionPerformed(ActionEvent e) {
		
		/*
		 * �޴��ٿ� ���� �̺�Ʈ
		 */
		if (e.getActionCommand().equals(find.getText())) {
			new FindDialog(this);
		}
		else if (e.getActionCommand().equals(fontEdit.getText())) {
			fontSelectCheck();
		}
		else if (e.getActionCommand().equals(newNote.getText())){
			ta.setText("");
			
		}
		else if (e.getActionCommand().equals(openNote.getText())){
			int i=file.showOpenDialog(this);
			if(i==0)openAndsave(0);                                               // ���� ���̾�αװ� ���� ���� �߰ų� ������ �޼ҵ� ����
		
		}
		else if (e.getActionCommand().equals(saveNote.getText())){
			int i=file.showSaveDialog(this);
			if(i==0)openAndsave(1);                                              // ���� ���̾�αװ� ���� ���� �߰ų� ������ �޼ҵ� ����
		}
		else if(e.getActionCommand().equals(exit.getText())){
			System.exit(0);
		}
		
	}

	public  void openAndsave(int i) {
		/*
		 * ���� ������ 0�� �޾ƿ��� ������ �о����
		 * 1�� �޾� ���� ��������
		 */
		String fileName=file.getName(file.getSelectedFile());
		File fileDirec=file.getCurrentDirectory();
		String s="";
		StringBuffer sb=new StringBuffer();
		if(i==0){
			try{
			ta.setText("");
			BufferedReader openWrite=new BufferedReader(new FileReader(fileDirec+"\\"+fileName));
			while((s=openWrite.readLine())!=null){
				sb.append(s+"\n");
			}
			ta.setText(sb.toString());
			
			}catch(FileNotFoundException e){
				new WarningDialog("������ ã������ �����ϴ�",this);
			}catch(IOException e){
				new WarningDialog("������ �д��߿� ����ġ ���� ������ �߻� �߽��ϴ�",this);
			}
		}
		else
			try{
				BufferedWriter saveWrite=new BufferedWriter(new FileWriter(fileDirec+"\\"+fileName));
				s=ta.getText();
				saveWrite.write(s);
				saveWrite.flush();
			}catch(IOException e1){
				new WarningDialog("�����ϴ� �߿� ������ �߻� �߽��ϴ�",this);
			}
	}

	public class NotePop extends JPopupMenu implements ActionListener{
	/*
	 * ����Ŭ���� ��Ŭ���� �˾��޴�
	 */
		JMenuItem mFind, mEdit;

		NotePop(JFrame f) {

			mEdit = new JMenuItem("�۲ú���");
			mFind= new JMenuItem("ã��");
			add(mEdit);
			add(mFind);
			mEdit.addActionListener(this);
			mFind.addActionListener(this);
		}

		public void actionPerformed(ActionEvent e) {

			if (e.getActionCommand().equals(mEdit.getText())) {
				fontSelectCheck();
			}
			else if (e.getActionCommand().equals(mFind.getText())) {
				new FindDialog(NotePad.this);
			}
		}
	}
	
	public void fontSelectCheck(){
		/*
		 * Text�� ���õǾ� ������ ���õ� �κи� ��Ʈ �ٲ�
		 * ������ �ȵǾ� ������ ��ü ��Ʈ �ٲ�
		 */
		if (ta.getSelectedText() != null) {
			start = ta.getSelectionStart();
			leng = ta.getSelectedText().length();
			fc = new FontChanged(NotePad.this, 0);
		}
		else {
			fc = new FontChanged(NotePad.this, 1);
		}
	}
	
	/*
	 * main
	 */
	public static void main(String args[]) {

		new NotePad();
	}

}