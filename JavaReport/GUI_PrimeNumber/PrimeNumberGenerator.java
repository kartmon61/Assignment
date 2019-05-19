package Assignment_6;

import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import java.awt.BorderLayout;
import java.awt.FlowLayout;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JTextField;
import javax.swing.SwingWorker;
import javax.swing.JTextArea;
import javax.swing.JProgressBar;
import javax.swing.JScrollBar;
import javax.swing.JButton;
import javax.swing.JScrollPane;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

public class PrimeNumberGenerator {

	private JFrame frmFindPromeNumbers;
	private JPanel pInput;
	private JLabel lblFindPrimeFrom;
	private JTextField txtInputFrom;
	private JLabel lblTo;
	private JTextField txtInputTo;
	private JProgressBar progressBar;
	private JButton btnStart;
	private JButton btnStop;
	private JScrollPane scrollPane;
	PrimeNumber number;
	private JTextArea outTextArea;
	private int array[];

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					PrimeNumberGenerator window = new PrimeNumberGenerator();
					window.frmFindPromeNumbers.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the application.
	 */
	public PrimeNumberGenerator() {
		initialize();
	}

	/**
	 * Initialize the contents of the frame.
	 */
	private void initialize() {
		frmFindPromeNumbers = new JFrame();
		frmFindPromeNumbers.setTitle("Find Prime Numbers");
		frmFindPromeNumbers.setBounds(100, 100, 600, 300);
		frmFindPromeNumbers.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		pInput = new JPanel();
		frmFindPromeNumbers.getContentPane().add(pInput, BorderLayout.NORTH);
		pInput.setLayout(new FlowLayout(FlowLayout.CENTER, 5, 5));

		lblFindPrimeFrom = new JLabel("Find prime from");
		pInput.add(lblFindPrimeFrom);

		txtInputFrom = new JTextField();
		pInput.add(txtInputFrom);
		txtInputFrom.setColumns(10);

		lblTo = new JLabel("to");
		pInput.add(lblTo);

		txtInputTo = new JTextField();
		pInput.add(txtInputTo);
		txtInputTo.setColumns(10);

		btnStart = new JButton("Start");

		// When pressing Start button
		btnStart.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				outTextArea.setText("");

				try {

					int from = Integer.parseInt(txtInputFrom.getText());
					int to = Integer.parseInt(txtInputTo.getText());

					if (from >= to) {
						throw new NumberCompareException();
					} else if (from >= 10000000 || to >= 10000000) {
						throw new NumberOverException();
					} else if (from < 2 || to < 2) {
						throw new NumberUnderException();
					}

					number = new PrimeNumber(from, to); // initialize swingWorker class

					number.execute(); // background thread starts

				} catch (NumberOverException overEx) {
					JOptionPane.showMessageDialog(null, overEx.getMessage(), "Over 8 digits",
							JOptionPane.ERROR_MESSAGE);

					txtInputFrom.setText("");
					txtInputTo.setText("");

				} catch (NumberUnderException underEx) {
					JOptionPane.showMessageDialog(null, underEx.getMessage(), "Digit must more than 1",
							JOptionPane.ERROR_MESSAGE);

					txtInputFrom.setText("");
					txtInputTo.setText("");

				} catch (NumberCompareException compareEx) {
					JOptionPane.showMessageDialog(null, compareEx.getMessage(), "Input digit Error",
							JOptionPane.ERROR_MESSAGE);

					txtInputFrom.setText("");
					txtInputTo.setText("");

				} catch (NumberFormatException formatException) {
					JOptionPane.showMessageDialog(null, "Please enter only integer values", "Invalid input",
							JOptionPane.ERROR_MESSAGE);

					txtInputFrom.setText("");
					txtInputTo.setText("");
				}

			}
		});

		pInput.add(btnStart);

		btnStop = new JButton("Stop");

		// When pressing Stop button
		btnStop.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				// action is cancel
				number.cancel(true);
				// start button is enable
				btnStart.setEnabled(true);
				// stop button is disable
				btnStop.setEnabled(false);
			}
		});
		pInput.add(btnStop);

		progressBar = new JProgressBar();
		progressBar.setStringPainted(true);
		frmFindPromeNumbers.getContentPane().add(progressBar, BorderLayout.SOUTH);
		outTextArea = new JTextArea();
		scrollPane = new JScrollPane(outTextArea);
		frmFindPromeNumbers.getContentPane().add(scrollPane, BorderLayout.CENTER);

	}

	// make PrimeNumber Thread class

	class PrimeNumber extends SwingWorker<Void, Integer> {

		int numTo;
		int numFrom;
		int cnt = 0;

		// constructor
		public PrimeNumber(int numFrom, int numTo) {
			this.numFrom = numFrom;
			this.numTo = numTo;
		}

		@Override
		protected Void doInBackground() throws Exception {

			// start button is disable
			btnStart.setEnabled(false);
			// stop button is enable
			btnStop.setEnabled(true);

			array = new int[numTo + 1];

			// set array initialize
			for (int i = 2; i <= numTo; i++) {
				array[i] = i;

			}

			// checking prime number
			for (int i = 2; i < Math.sqrt(numTo); i++) {

				if (array[i] == 0) {
					continue;
				}
				// when find a multiple number index, make array index 0
				for (int j = i + i; j <= numTo; j += i) {
					array[j] = 0;
				}
			}

			// print out prime number
			for (int i = numFrom; i <= numTo; i++) {
				if (array[i] != 0) {
					outTextArea.append("" + i + "\n");
					// make thread time set 300
					Thread.sleep(300);
					// count prime number
					cnt++;
				}
				
				
				// progressBar output
				progressBar.setValue((i - numFrom + 1) * 100 / (numTo - numFrom + 1));
			}
			// print prime number count
			JOptionPane.showMessageDialog(null, "Found " + cnt + " prime numbers", "Process is over",
					JOptionPane.OK_OPTION);
			// start button is enable
			btnStart.setEnabled(true);
			// stop button is disable
			btnStop.setEnabled(false);
			return null;
		}

	}

}
