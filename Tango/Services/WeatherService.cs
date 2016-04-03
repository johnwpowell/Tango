using System;
using System.Linq;
using System.Threading;
using System.Threading.Tasks;
using Windows.Devices.Enumeration;
using Windows.Devices.SerialCommunication;
using Tango.Models;

namespace Tango.Services
{
    public class WeatherService
    {
        private SerialDevice serialDevice;
        private CancellationTokenSource ReadCancellationTokenSource;

        public async Task Connect(string comPort = "COM7")
        {
            var devices = await DeviceInformation.FindAllAsync(
                SerialDevice.GetDeviceSelector(comPort),
                null);

            if (!devices.Any())
            {
                throw new Exception($"{comPort} not found");
            }

            serialDevice = await SerialDevice.FromIdAsync(devices.First().Id);
            if (serialDevice == null)
            {
                throw new Exception($"Unable to connect to {comPort}");
            }

            //// Configure serial settings
            //serialDevice.WriteTimeout = TimeSpan.FromMilliseconds(1000);
            //serialDevice.ReadTimeout = TimeSpan.FromMilliseconds(1000);
            //serialDevice.BaudRate = 9600;
            //serialDevice.Parity = SerialParity.None;
            //serialDevice.StopBits = SerialStopBitCount.One;
            //serialDevice.DataBits = 8;
            //serialDevice.Handshake = SerialHandshake.None;

            ReadCancellationTokenSource = new CancellationTokenSource();
        }

        public async Task Update(WeatherViewModel weather)
        {
            try
            {
  

            }
            catch (Exception ex)
            {
                weather.IsError = true;
                weather.Message = ex.Message;
            }
        }
    }
}
