import os
import pickle
import csv
from googleapiclient.discovery import build

# Function to download data from Google Sheets to a CSV file
def download_gsheet_to_csv(spreadsheet_id, worksheet_name, csv_file_path, credentials_path):
    """Download data from Google Sheets to CSV."""
    try:
        # Check if the credentials file exists
        if not os.path.exists(credentials_path):
            raise FileNotFoundError(f"Credentials file {credentials_path} not found. Please perform authentication.")
        
        # Authentication using the token file
        with open(credentials_path, 'rb') as token:
            credentials = pickle.load(token)

        # Create the API client
        service = build('sheets', 'v4', credentials=credentials)

        # Read data from the spreadsheet
        range_name = worksheet_name
        result = service.spreadsheets().values().get(spreadsheetId=spreadsheet_id, range=range_name).execute()
        values = result.get('values', [])

        # Check if data is available
        if not values:
            print("The sheet is empty or no data found.")
            return

        # Write data to the CSV file
        with open(csv_file_path, 'w', newline='', encoding='cp1251') as csvfile:
            writer = csv.writer(csvfile)
            writer.writerows(values)

        print(f"Data successfully saved to file {csv_file_path}")
    except Exception as e:
        print(f"Error downloading data: {e}")

if __name__ == "__main__":
    # Console input
    print("Enter data to download from Google Sheets:")
    spreadsheet_id = input("Spreadsheet ID: ").strip()
    worksheet_name = input("Worksheet name: ").strip()

    # Input with default handling
    csv_file_path = input("Path to save CSV (default 'output.csv', type 'd' for default): ").strip()
    if csv_file_path.lower() == 'd' or not csv_file_path:
        csv_file_path = 'output.csv'

    credentials_path = input("Path to credentials file (default 'token.pickle', type 'd' for default): ").strip()
    if credentials_path.lower() == 'd' or not credentials_path:
        credentials_path = 'token.pickle'

    # Call the function
    download_gsheet_to_csv(spreadsheet_id, worksheet_name, csv_file_path, credentials_path)
