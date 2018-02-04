package 행맨게임;
import java.util.*;
import java.io.*;

//words.txt 파일을 읽고 파일에서 랜덤하게 단어를 추출하는 클래스
class Words {
	final int WORDMAX = 25143; // words.txt파일에 들어 있는 총 단어의 개수
	private String fileName; // 단어 파일 이름. 현재는 words.txt
	private Random r = new Random(); // 난수 발생기

	public Words(String fileName) {
		this.fileName = fileName;
	}

	public String getRandomWord() {
		// 파일을 읽기 위한 BufferedReader 객체를 생성한다.
		BufferedReader in = null;      
		try {
			// 파일을 열고 파일을 읽기 위한 BufferedReader 객체 생성
			in = new BufferedReader(new FileReader(fileName));
		}
		catch(FileNotFoundException e) {
			System.out.println("file not found error");
			System.exit(0);
		}
		int n = r.nextInt(WORDMAX); // 랜덤한 라인 번호 생성. n 번째 단어를 게임에 사용
		return readWord(in, n); // in 파일에서 n 번째 라인의 단어를 읽어서 리턴
	}

	// in 파일에서 n 번째 라인의 단어를 읽어 리턴하는 메소드
	private String readWord(BufferedReader in, int n) {
		String line=null; // 한 라인을 저장할 문자열 객체. 한 라인에는 하나의 단어만 있음
		try {
			while (n>0) {
				line = in.readLine(); // 파일에서 한 라인(한 단어)를 읽는다.
				if(line == null) // eof를 만나면 문제 발생. 루프 종료
					break;
				n--;
			}
		} catch (IOException e) {
			System.exit(0);
		}
		return line; // n 번째 라인의 단어 리턴
	}
}