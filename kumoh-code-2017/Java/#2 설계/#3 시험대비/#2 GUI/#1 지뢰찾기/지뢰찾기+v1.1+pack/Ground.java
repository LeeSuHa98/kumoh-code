import java.awt.event.*;
import javax.swing.*;

public class Ground extends JButton {
	int row, col;
	boolean hasMine, isOpen, isMarked;
	public Ground(int row, int col) { // Ground ������
		super(new ImageIcon(Ground.class.getResource("src/img/default.png")));
		setSize(20, 20);
		setContentAreaFilled(false);
		
		this.row=row;
		this.col=col;
		hasMine=false;
		isOpen=false;
		isMarked=false;
		
		addMouseListener(new MouseAdapter() { // mouseAdapter �߰�
			public void mouseReleased(MouseEvent me) { // override
				if(!isOpen && !Field.isAllOpen()) { // ������ ������ �ʾҰ� ���� ������ �ʾ��� ��
					if(SwingUtilities.isRightMouseButton(me)) { // ��Ŭ�� ��
						setIcon(new ImageIcon(Ground.class.getResource((isMarked) ? "src/img/default.png" : "src/img/marked.png")));
						isMarked=!isMarked;
					} else if(SwingUtilities.isLeftMouseButton(me) && !isMarked) { // ��Ŭ�� �� ���� ǥ�ø� �� ���� ��
						if(hasMine) { // ���ڸ� ����� ��
							Field.isSuccess=false; // ���ж�� ���� ǥ��
							for(int i=0; i<Field.VERTICAL*Field.HORIZONTAL; i++) { // ���� ���� ��
								if(Field.buttons[i%Field.HORIZONTAL+2][i/Field.HORIZONTAL+2].hasMine) { // ������ ���� ������ ��
									Field.buttons[i%Field.HORIZONTAL+2][i/Field.HORIZONTAL+2].setIcon(new ImageIcon(Ground.class.getResource("src/img/mine.png")));
								} else { // ������ ���� �׳� ���� ��
									Field.buttons[i%Field.HORIZONTAL+2][i/Field.HORIZONTAL+2].setIcon(new ImageIcon(Ground.class.getResource("src/img/open"+Field.countMine(Field.buttons[i%Field.HORIZONTAL+2][i/Field.HORIZONTAL+2])+".png")));
								} // if
								Field.buttons[i%Field.HORIZONTAL+2][i/Field.HORIZONTAL+2].isOpen=true;
							} // for
						} else { // ���ڰ� ���� ���� ����� ��
							setIcon(new ImageIcon(Ground.class.getResource("src/img/open"+Field.countMine((Ground)me.getSource())+".png")));
							isOpen=true;
							while(Field.checkButtons()) { // countMine()�� 0�̰� �ֺ��� ���� �������� ���� ���� ���� ��
								for(int i=0; i<Field.VERTICAL*Field.HORIZONTAL; i++) { // countMine()�� 0�̰� �ֺ��� ���� �������� ���� �� �ֺ��� ��
									if(Field.buttons[i%Field.HORIZONTAL+2][i/Field.HORIZONTAL+2].isOpen && Field.countOpen(Field.buttons[i%Field.HORIZONTAL+2][i/Field.HORIZONTAL+2])<8 && Field.countMine(Field.buttons[i%Field.HORIZONTAL+2][i/Field.HORIZONTAL+2])==0) {
										Field.open(Field.buttons[i%Field.HORIZONTAL+2][i/Field.HORIZONTAL+2]);
									} // if
								} // for
							} // while
						} // if
						isOpen=true;
					} // if
					if(Field.isAllOpen()) { // ���� ���� ������ ��
						Main.label.setText((Field.isSuccess) ? "����!" : "����...");
					} // if
				} // if
			} // �޼���
			public void mousePressed(MouseEvent me) { // override
				if(!isOpen && !isMarked) {
					setIcon(new ImageIcon(Ground.class.getResource("src/img/clicked.png")));
				}
			}
		}); // mouseAdapter
	} // ������
} // Ŭ����