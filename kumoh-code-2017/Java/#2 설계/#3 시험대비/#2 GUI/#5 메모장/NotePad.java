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
		
		super("메모장");																// Frame 창 타이틀명 지정
		co = getContentPane();                                                 // Frame에 붙이기 위해 Container 객체 생성
		ta = new JTextPane();                                                   // 선택된 Text만 폰트 적용을 위해 TextPane 사용
		sd = ta.getStyledDocument();                                        //  선택된 Text만 폰트 적용을 StyleDocument 객체 생성
		sp = new JScrollPane(ta);
        
		/*
         * 메뉴바와 메뉴아이템 객체 생성 
         */
		mainBar = new JMenuBar();
		menuFile = new JMenu("파일");
		menuEdit = new JMenu("편집");
		find = new JMenuItem("찾기    (Ctrl+F)");
		fontEdit = new JMenuItem("서식    (Ctrl+E)");
		newNote=new JMenuItem("새로쓰기");
		openNote=new JMenuItem("열기    (Ctrl+O)");
		saveNote=new JMenuItem("저장    (Ctrl+S)");
		exit=new JMenuItem("끝내기");
		file=new JFileChooser();
		
		/*
		 * 메뉴바에 메뉴아이템을 붙이고
		 * 이벤트 리스너 장착
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
			 * ta 에 마우스 이벤트 추가
			 * 마우스 우클릭시 팝업창 띄움
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
			 * 단축키 설정
			 */
			public void keyReleased(KeyEvent e){
				
				/*
				 * Ctrl 키가 눌러져 있음 실행
				 */
				if(e.isControlDown()){
					if(e.getKeyCode()==KeyEvent.VK_E){                      //Ctrl 눌러진 상태에서 E 키를 누르면 폰트설정 다이얼로그
						fontSelectCheck();
					}
					else if(e.getKeyCode()==KeyEvent.VK_F){              //Ctrl 눌러진 상태에서 F 키를 누르면 찾기 다이얼로그
						new FindDialog(NotePad.this);
					}
					else if(e.getKeyCode()==KeyEvent.VK_O){              //Ctrl 눌러진 상태에서 O 키를 누르면 찾기 파일열기창 
						int i=file.showOpenDialog(NotePad.this);
						if(i==0)openAndsave(0);
					}
					else if(e.getKeyCode()==KeyEvent.VK_S){              //Ctrl 눌러진 상태에서 F 키를 누르면 열기 다이얼로그 뜸
						int i=file.showSaveDialog(NotePad.this);
						if(i==0)openAndsave(1);
					}
				}

			}
		});
	}

	public void actionPerformed(ActionEvent e) {
		
		/*
		 * 메뉴바에 대한 이벤트
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
			if(i==0)openAndsave(0);                                               // 파일 다이얼로그가 문제 없이 뜨거나 닫히면 메소드 실행
		
		}
		else if (e.getActionCommand().equals(saveNote.getText())){
			int i=file.showSaveDialog(this);
			if(i==0)openAndsave(1);                                              // 파일 다이얼로그가 문제 없이 뜨거나 닫히면 메소드 실행
		}
		else if(e.getActionCommand().equals(exit.getText())){
			System.exit(0);
		}
		
	}

	public  void openAndsave(int i) {
		/*
		 * 인자 값으로 0을 받아오면 파일을 읽어오고
		 * 1을 받아 오면 파일저장
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
				new WarningDialog("파일을 찾을수가 없습니다",this);
			}catch(IOException e){
				new WarningDialog("파일을 읽는중에 예상치 못한 에러가 발생 했습니다",this);
			}
		}
		else
			try{
				BufferedWriter saveWrite=new BufferedWriter(new FileWriter(fileDirec+"\\"+fileName));
				s=ta.getText();
				saveWrite.write(s);
				saveWrite.flush();
			}catch(IOException e1){
				new WarningDialog("저장하는 중에 문제가 발생 했습니다",this);
			}
	}

	public class NotePop extends JPopupMenu implements ActionListener{
	/*
	 * 내부클래스 우클릭시 팝업메뉴
	 */
		JMenuItem mFind, mEdit;

		NotePop(JFrame f) {

			mEdit = new JMenuItem("글꼴변경");
			mFind= new JMenuItem("찾기");
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
		 * Text가 선택되어 있으면 선택된 부분만 폰트 바꿈
		 * 선택이 안되어 있으면 전체 폰트 바꿈
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