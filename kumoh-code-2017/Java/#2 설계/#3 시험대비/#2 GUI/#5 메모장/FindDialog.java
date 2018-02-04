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
	 * ã�� ���̾�α�
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
		super(f, "ã��", false);															// ���̾�α� Ÿ��Ʋ ����
		this.f = f;
		co = getContentPane();															// Container ��ü ����
		co.setLayout(new BorderLayout(10, 10));									// �������̾ƿ� ���� �¿� ���� ���� 10��ŭ
		
		/*
		 * ������Ʈ ��ü ������ ���̾�α׿� ������Ʈ ����
		 */
		tf = new JTextField(20);
		tChange = new JTextField(20);
		nextFind = new JButton("���� ã��");
		cancel = new JButton("   �� ��   ");
		change = new JCheckBox("ã�� �ٲٱ�");
		la = new JLabel("ã�� ���ڿ��� �Է�  ");
		la2 = new JLabel("�ٲ� ���ڿ��� �Է�  ");
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
		 * �̺�Ʈ ������ ����
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
		 * "/n" Ű ���ִ� �۾�
		 * String s�� TexPane�� �ִ� ���ڸ� �о�ö� enter���� ���� �Ѿ�ͼ� �ε����� �����ȴ�
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
			 * ã��� ã�ƹٲٱ�
			 */
		if (e.getActionCommand().equals(nextFind.getText())) {
			String findText = tf.getText();
			allText = setFind();
			int leng = tf.getText().length();
			int start = f.ta.getSelectionEnd();
			int first = allText.indexOf(findText, start);
			int last = (first == -1 ? -1 : first + leng);
			f.ta.select(first, last);
			if (nextFind.getText().equals("ã�� �ٲٱ�")) {
				if (first == -1) {
				}
				else {
					f.ta.replaceSelection(tChange.getText());
				}
			}
			if (first == -1) {
				new ConfirmDialog(this, "ã�� ���ڿ��� �����ϴ� ó������ ã���ðڽ��ϱ�?");
			}
		}
		else {
			setVisible(false);
		}
	}

	public void itemStateChanged(ItemEvent e) {
		/*
		 * üũ���� Ȯ���� ã�� �ٲٱ� TextField ���� �Ǵ� ����
		 */
		if (e.getStateChange() == 1) {
			p3.add(la2, "West");
			p3.add(tChange, "Center");
			nextFind.setText("ã�� �ٲٱ�");
		}
		else {
			p3.remove(la2);
			p3.remove(tChange);
			nextFind.setText("���� ã��");
		}
		repaint();
	}
}
