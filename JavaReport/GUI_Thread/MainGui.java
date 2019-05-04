package prac;

import java.awt.EventQueue;

import javax.swing.JFrame;
import java.awt.Color;
import javax.swing.JPanel;
import java.awt.BorderLayout;
import java.awt.Dimension;
import java.awt.FlowLayout;
import javax.swing.JTextField;
import javax.swing.JLabel;
import javax.swing.JButton;
import javax.swing.JProgressBar;
import javax.swing.JScrollBar;
import java.awt.event.ActionListener;
import java.util.Random;
import java.awt.event.ActionEvent;
import javax.swing.JTextArea;
import javax.swing.JScrollPane;

public class MainGui {

	private JFrame frame;
	private JPanel pnInput;
	private JPanel pnStatus;
	private JLabel lbInputANumber;
	private JTextField inText;
	private JButton btnRun;
	private JButton btnCancel;
	private JProgressBar progressBar;
	private JLabel lblStatus;
	private JPanel pnOutput;
	Thread runThread;
	private JTextArea outTextArea;
	private JScrollPane scrollPane;
	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					MainGui window = new MainGui();
					window.frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the application.
	 */
	public MainGui() {
		initialize();
	}

	/**
	 * Initialize the contents of the frame.
	 */
	private void initialize() {
		frame = new JFrame();
		frame.setBackground(Color.WHITE);
		frame.setBounds(100, 100, 450, 300);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		pnInput = new JPanel();
		pnInput.setPreferredSize(new Dimension(10, 35));
		frame.getContentPane().add(pnInput, BorderLayout.NORTH);
		pnInput.setLayout(new FlowLayout(FlowLayout.CENTER, 5, 5));
		
		lbInputANumber = new JLabel("Number of loops");
		pnInput.add(lbInputANumber);
		
		inText = new JTextField();
		pnInput.add(inText);
		inText.setColumns(10);
		
		btnRun = new JButton("Run");
		btnRun.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				outTextArea.setText("");
				int num = Integer.parseInt(inText.getText());
				runThread = new Thread(new RandomNumber(num));
				runThread.start();
				
			}
		});
		pnInput.add(btnRun);
		
		btnCancel = new JButton("Cancel");
		btnCancel.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				btnRun.setEnabled(true);
				btnCancel.setEnabled(false);
				runThread.interrupt();
			}
		});
		pnInput.add(btnCancel);
		
		pnStatus = new JPanel();
		pnStatus.setPreferredSize(new Dimension(10, 25));
		frame.getContentPane().add(pnStatus, BorderLayout.SOUTH);
		
		progressBar = new JProgressBar();
		progressBar.setStringPainted(true);
		pnStatus.add(progressBar);

		
		
		lblStatus = new JLabel("Status");
		pnStatus.add(lblStatus);
		
		pnOutput = new JPanel();
		frame.getContentPane().add(pnOutput, BorderLayout.CENTER);
		pnOutput.setLayout(new BorderLayout(0, 0));
		
		outTextArea = new JTextArea();
		
		
		scrollPane = new JScrollPane(outTextArea);
		pnOutput.add(scrollPane);
	}
	
	class RandomNumber implements Runnable{
		
		int num;
		
		public RandomNumber(int num) {
			this.num = num;
		}
		
		
		
		
		@Override
		public void run() {
				int cnt =0;
				btnRun.setEnabled(true);
				btnCancel.setEnabled(false);
				try {
					
					for(int i=0;i<num;i++) {
						
						btnRun.setEnabled(false);
						btnCancel.setEnabled(true);
						Random rand = new Random();
						double number = rand.nextDouble();
						Thread.sleep(300);
						outTextArea.append(i+1+". Random number = " + number+ "\n");
						progressBar.setValue((i+1)*100/num);
						cnt++;
						
					}
					
					btnRun.setEnabled(true);
					btnCancel.setEnabled(false);
					lblStatus.setText("Finish "+cnt+" works.");
					
				} catch (InterruptedException e) {
					e.printStackTrace();
				}
				
			}
			
		}
		
	}


