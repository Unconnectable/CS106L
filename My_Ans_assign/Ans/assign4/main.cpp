/*
 * CS106L Assignment 4: Weather Forecast
 * Created by Haven Whitney with modifications by Fabio Ibanez & Jacob Roberts-Baca.
 */

#include <algorithm>
#include <random>
#include <vector>
#include <iostream>


/* #### Please feel free to use these values, but don't change them! #### */
double kMaxTempRequirement = 5;
double uAvgTempRequirement = 60;

struct Forecast { 
  double min_temp;
  double max_temp;
  double avg_temp;
};

Forecast compute_forecast(const std::vector<double>& dailyWeather) {
  // STUDENT TODO 1: return a forecast for the daily weather that is passed in.
  double min_temp_ = *std::min_element(dailyWeather.begin(),dailyWeather.end());
  double max_temp_ = *std::max_element(dailyWeather.begin(),dailyWeather.end());
  double avg_temp_ = std::accumulate(dailyWeather.begin(),dailyWeather.end(),0.0)/(double)dailyWeather.size();
  return Forecast{min_temp_,max_temp_,avg_temp_};
  
}

std::vector<Forecast> get_forecasts(const std::vector<std::vector<double>>& weatherData) {
  /*
   * STUDENT TODO 2: returns a vector of Forecast structs for the weatherData which contains
   * std::vector<double> which contain values for the weather on that day.
   */
  std::vector<Forecast> temp_forecasts(weatherData.size());
  std::transform(weatherData.begin(),weatherData.end(),temp_forecasts.begin(),compute_forecast);
  return temp_forecasts;
}

std::vector<Forecast> get_filtered_data(const std::vector<Forecast>& forecastData) {
  // STUDENT TODO 3: return a vector with Forecasts filtered for days with specific weather.
  auto filter = [](Forecast x){
    return (  ((x.max_temp - x.min_temp) <= kMaxTempRequirement) || (x.avg_temp<uAvgTempRequirement) );
};

  std::vector<Forecast> filteredData = forecastData;
  filteredData.erase(std::remove_if(filteredData.begin(),filteredData.end(),filter),filteredData.end());
  return filteredData;
}

std::vector<Forecast> get_shuffled_data(const std::vector<Forecast>& forecastData) {
  // STUDENT TODO 4: Make use of a standard library algorithm to shuffle the data!
  std::vector<Forecast> forecastData_copy(forecastData.begin(),forecastData.end());
  std::random_device rd;
  std::mt19937 g(rd());
  std::shuffle(forecastData_copy.begin(),forecastData_copy.end(),g);
  
  return forecastData_copy;
  
}

std::vector<Forecast> run_weather_pipeline(const std::vector<std::vector<double>>& weatherData) {
  // STUDENT TODO 5: Put your functions together to run the weather pipeline!
  std::vector<Forecast> forecastData = get_forecasts(weatherData);
  std::vector<Forecast> forecastData_1 = get_filtered_data(forecastData);
  std::vector<Forecast> forecastData_2 = get_shuffled_data(forecastData);
  return forecastData_2;
}

/* #### Please don't change this line! #### */
#include "utils.cpp"