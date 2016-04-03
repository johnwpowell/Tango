using System;
using Windows.UI.Xaml;
using Tango.Models;
using Tango.Services;

namespace Tango
{
    public sealed partial class MainPage
    {
        public WeatherViewModel weather = new WeatherViewModel();
        private readonly WeatherService weatherService = new WeatherService();
        private readonly DispatcherTimer timer = new DispatcherTimer();

        public MainPage()
        {
            InitializeComponent();
            DataContext = weather;
            timer.Interval = TimeSpan.FromSeconds(2);
            timer.Tick += TimerTick;

            Loaded += MainPageLoaded;
        }

        private async void MainPageLoaded(object sender, RoutedEventArgs e)
        {
            await weatherService.Connect();
            weather.Message = "Connected";
        }

        private async void TimerTick(object sender, object e)
        {
            await weatherService.Update(weather);
        }
    }
}
