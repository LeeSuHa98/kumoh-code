import java.awt.BorderLayout;
import java.awt.Container;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.ItemEvent;
import java.awt.event.ItemListener;
import java.util.StringTokenizer;
import javax.swing.JButton;
import javax.swing.JCheckBox;
import javax.swing.JDialog;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;

public class FindDialog extends JDialog implements ActionListener, ItemListener{
	
	/*
	 * 찾기 다이얼로그
	 */

	JTextField tf, tChange;

	JButton nextFind, cancel;

	JCheckBox change;

	JLabel la, la2;

	JPanel p1, p2, p3, p4;

	NotePad f;

	String allText;

	Container co;

	FindDialog(NotePad f) {
		super(f, "찾기", false);															// 다이얼로그 타이틀 설정
		this.f = f;
		co = getContentPane();															// Container 객체 생성
		co.setLayout(new BorderLayout(10, 10));									// 보더레이아웃 설정 좌우 상하 간격 10만큼
		
		/*
		 * 컴포넌트 객체 생성과 다이얼로그에 컴포넌트 장착
		 */
		tf = new JTextField(20);
		tChange = new JTextField(20);
		nextFind = new JButton("다음 찾기");
		cancel = new JButton("   취 소   ");
		change = new JCheckBox("찾아 바꾸기");
		la = new JLabel("찾을 문자열을 입력  ");
		la2 = new JLabel("바꿀 문자열을 입력  ");
		p1 = new JPanel(new BorderLayout(10, 20));
		p2 = new JPanel();
		p3 = new JPanel(new BorderLayout(10, 20));
		p4 = new JPanel(new GridLayout(2, 1, 10, 10));
		p1.add(la, "West");
		p1.add(tf, "Center");
		p2.add(nextFind);
		p2.add(cancel);
		p4.add(p1);
		p4.add(p3);
		co.add(p4, "Center");
		co.add(change, "East");
		co.add(p2, "South");
		
		/*
		 * 이벤트 리스너 장착
		 */
		nextFind.addActionListener(this);
		cancel.addActionListener(this);
		change.addItemListener(this);

		setLocation(730, 230);
		pack();
		setVisible(true);
	}

	public String setFind() {
		/*
		 * "/n" 키 없애는 작업
		 * String s로 TexPane에 있는 문자를 읽어올때 enter값이 같이 넘어와서 인덱스가 증가된다
		 * 
		 */
		String s = f.ta.getText();
		StringTokenizer st = new StringTokenizer(s, "\n");
		s = "";
		while (st.hasMoreTokens()) {
			s += st.nextToken();
		}
		return s;
	}

	public void actionPerformed(ActionEvent e) {
		
			/*
			 * 찾기와 찾아바꾸기
			 */
		if (e.getActionCommand().equals(nextFind.getText())) {
			String findText = tf.getText();
			allText = setFind();
			int leng = tf.getText().length();
			int start = f.ta.getSelectionEnd();
			int first = allText.indexOf(findText, start);
			int last = (first == -1 ? -1 : first + leng);
			f.ta.select(first, last);
			if (nextFind.getText().equals("찾아 바꾸기")) {
				if (first == -1) {
				}
				else {
					f.ta.replaceSelection(tChange.getText());
				}
			}
			if (first == -1) {
				new ConfirmDialog(this, "찾는 문자열이 없습니다 처음부터 찾으시겠습니까?");
			}
		}
		else {
			setVisible(false);
		}
	}

	public void itemStateChanged(ItemEvent e) {
		/*
		 * 체크유무 확인후 찾아 바꾸기 TextField 생성 또는 제거
		 */
		if (e.getStateChange() == 1) {
			p3.add(la2, "West");
			p3.add(tChange, "Center");
			nextFind.setText("찾아 바꾸기");
		}
		else {
			p3.remove(la2);
			p3.remove(tChange);
			nextFind.setText("다음 찾기");
		}
		repaint();
	}
}
