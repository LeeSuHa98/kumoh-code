import java.awt.event.*;
import javax.swing.*;

public class Ground extends JButton {
	int row, col;
	boolean hasMine, isOpen, isMarked;
	public Ground(int row, int col) { // Ground 생성자
		super(new ImageIcon(Ground.class.getResource("src/img/default.png")));
		setSize(20, 20);
		setContentAreaFilled(false);
		
		this.row=row;
		this.col=col;
		hasMine=false;
		isOpen=false;
		isMarked=false;
		
		addMouseListener(new MouseAdapter() { // mouseAdapter 추가
			public void mouseReleased(MouseEvent me) { // override
				if(!isOpen && !Field.isAllOpen()) { // 게임이 끝나지 않았고 땅이 열리지 않았을 때
					if(SwingUtilities.isRightMouseButton(me)) { // 우클릭 시
						setIcon(new ImageIcon(Ground.class.getResource((isMarked) ? "src/img/default.png" : "src/img/marked.png")));
						isMarked=!isMarked;
					} else if(SwingUtilities.isLeftMouseButton(me) && !isMarked) { // 좌클릭 시 지뢰 표시를 안 했을 때
						if(hasMine) { // 지뢰를 밟았을 때
							Field.isSuccess=false; // 실패라는 것을 표시
							for(int i=0; i<Field.VERTICAL*Field.HORIZONTAL; i++) { // 블럭을 전부 엶
								if(Field.buttons[i%Field.HORIZONTAL+2][i/Field.HORIZONTAL+2].hasMine) { // 열려는 땅이 지뢰일 때
									Field.buttons[i%Field.HORIZONTAL+2][i/Field.HORIZONTAL+2].setIcon(new ImageIcon(Ground.class.getResource("src/img/mine.png")));
								} else { // 열려는 땅이 그냥 땅일 때
									Field.buttons[i%Field.HORIZONTAL+2][i/Field.HORIZONTAL+2].setIcon(new ImageIcon(Ground.class.getResource("src/img/open"+Field.countMine(Field.buttons[i%Field.HORIZONTAL+2][i/Field.HORIZONTAL+2])+".png")));
								} // if
								Field.buttons[i%Field.HORIZONTAL+2][i/Field.HORIZONTAL+2].isOpen=true;
							} // for
						} else { // 지뢰가 없는 땅을 밟았을 때
							setIcon(new ImageIcon(Ground.class.getResource("src/img/open"+Field.countMine((Ground)me.getSource())+".png")));
							isOpen=true;
							while(Field.checkButtons()) { // countMine()이 0이고 주변이 전부 열리지는 않은 땅이 있을 때
								for(int i=0; i<Field.VERTICAL*Field.HORIZONTAL; i++) { // countMine()이 0이고 주변이 전부 열리지는 않은 블럭 주변을 엶
									if(Field.buttons[i%Field.HORIZONTAL+2][i/Field.HORIZONTAL+2].isOpen && Field.countOpen(Field.buttons[i%Field.HORIZONTAL+2][i/Field.HORIZONTAL+2])<8 && Field.countMine(Field.buttons[i%Field.HORIZONTAL+2][i/Field.HORIZONTAL+2])==0) {
										Field.open(Field.buttons[i%Field.HORIZONTAL+2][i/Field.HORIZONTAL+2]);
									} // if
								} // for
							} // while
						} // if
						isOpen=true;
					} // if
					if(Field.isAllOpen()) { // 땅이 전부 열렸을 때
						Main.label.setText((Field.isSuccess) ? "성공!" : "실패...");
					} // if
				} // if
			} // 메서드
			public void mousePressed(MouseEvent me) { // override
				if(!isOpen && !isMarked) {
					setIcon(new ImageIcon(Ground.class.getResource("src/img/clicked.png")));
				}
			}
		}); // mouseAdapter
	} // 생성자
} // 클래스