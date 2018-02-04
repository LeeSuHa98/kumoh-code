import java.awt.Container;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JDialog;
import javax.swing.JLabel;
import javax.swing.JPanel;

public class ConfirmDialog extends JDialog implements ActionListener{
	
	/*
	 * 확인 취소 다이얼 로그
	 */
	JLabel msg;

	JButton confirm, cancel;

	JPanel p1, p2;

	JDialog d;

	ConfirmDialog(JDialog d, String s) {

		super(d, false);
		this.d = d;
		Container co = getContentPane();
		msg = new JLabel(s);
		p1 = new JPanel();
		p2 = new JPanel();
		confirm = new JButton("예");
		cancel = new JButton("아니오");
		p1.add(msg);
		p2.add(confirm);
		p2.add(cancel);
		co.add(p1, "Center");
		co.add(p2, "South");
		confirm.addActionListener(this);
		cancel.addActionListener(this);
		setLocation(340, 240);
		pack();
		setVisible(true);
	}

	public void actionPerformed(ActionEvent e) {

		if (e.getActionCommand().equals(confirm.getText())) {
			setVisible(false);
		}
		else {
			d.setVisible(false);
		}
	}
}
