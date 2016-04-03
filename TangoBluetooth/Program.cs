using System;
using System.IO.Ports;
using System.Threading;

namespace TangoBluetooth
{
    public class TangoProgram
    {
        private static SerialPort serialPort;
        private static int interval = 3000;

        public static void Main()
        {
            var connected = false;
            while (!connected)
            {
                // configure the serial port
                serialPort = new SerialPort
                {
                    PortName = "COM15",
                    BaudRate = 9600,
                    DataBits = 8,
                    Parity = Parity.None,
                    StopBits = StopBits.One,
                    ReadTimeout = interval
                };

                try
                {
                    serialPort.Open();
                    connected = true;
                }
                catch (Exception ex)
                {
                    Console.WriteLine(ex.Message);
                    Thread.Sleep(1000);
                }
            }

            Console.WriteLine("Connected.");

            while (true)
            {
                Console.Write("Requesting Weather...");
                serialPort.Write("!");
                Thread.Sleep(100);
                try
                {
                    var weather = serialPort.ReadLine();
                    Console.WriteLine("Success");
                    Console.WriteLine(weather);
                }
                catch (TimeoutException ex)
                {
                    Console.WriteLine(ex.Message);
                }

                Thread.Sleep(interval);
            }
        }
    }
}
