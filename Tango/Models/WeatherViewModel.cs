namespace Tango.Models
{
    public class WeatherViewModel: ViewModelBase
    {
        private decimal temperature;
        private bool isError;
        private string message;

        public bool IsError
        {
            get { return isError; }
            set
            {
                isError = value;
                OnPropertyChanged("IsError");
            }
        }

        public string Message
        {
            get { return message; }
            set
            {
                message = value;
                OnPropertyChanged("Message");
            }
        }

        public decimal Temperature
        {
            get { return temperature; }
            set
            {
                temperature = value;
                OnPropertyChanged("Temperature");
            }
        }
    }
}
