import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Container;
import java.awt.Point;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;

public class MouseEventDemo extends JFrame {
	JLabel label1, label2;
	JButton button1;
	public MouseEventDemo()
	{
		super("test");
		initializeComponents();
	}
	private void initializeComponents() {
		Container c = getContentPane();
		c.setLayout(new BorderLayout());
		label1 = new JLabel( "           " );
		label2 = new JLabel( "           ");
		c.add(label1, BorderLayout.NORTH );
		c.add(label2, BorderLayout.SOUTH);

		MouseEventHandler ob = new MouseEventHandler();
		this.addMouseListener(ob);
		this.addMouseMotionListener(ob);
		setSize(300, 300);
		setLocation(300, 300);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setVisible(true);      
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		MouseEventDemo app = new MouseEventDemo();
	}

	//����Ŭ������ ����� ����Ŭ������ ������Ʈ ��� ����
	class MouseEventHandler implements MouseListener,MouseMotionListener{
		@Override
		public void mouseDragged(MouseEvent e) {
			// TODO Auto-generated method stub

		}
		// e.getX() �� ������� â�� �������� ��Ÿ���� ��ǥ�̸� e.getXOnScreen()�� ���� ������â�� �������� �Ѵ�.
		@Override
		public void mouseMoved(MouseEvent e) {
			// TODO Auto-generated method stub
			label1.setText("Moved: "+ e.getX()+","+e.getY());
		}
		@Override
		public void mouseClicked(MouseEvent e) {
			// TODO Auto-generated method stub
			label1.setText("Clicked"+ e.getX()+","+e.getY());

		}
		@Override
		public void mousePressed(MouseEvent e) {
			// TODO Auto-generated method stub
			label1.setText("Pressed: "+ e.getX()+","+e.getY());

		}
		@Override
		public void mouseReleased(MouseEvent e) {
			// TODO Auto-generated method stub
			label1.setText("Released: "+ e.getX()+","+e.getY());

		}
		@Override
		public void mouseEntered(MouseEvent e) {
			// TODO Auto-generated method stub
			label1.setText("Entered: "+ e.getX()+","+e.getY());

		}
		@Override
		public void mouseExited(MouseEvent e) {
			// TODO Auto-generated method stub
			label1.setText("Exited: "+ e.getX()+","+e.getY());

		}
	}
}

