import os
import pickle
import csv
from googleapiclient.discovery import build

# Function to upload data from a CSV file to Google Sheets
def upload_csv_to_gsheet(csv_file_path, spreadsheet_id, worksheet_name, credentials_path):
    """Uploads data from a CSV file to Google Sheets."""
    try:
        # Check if the credentials file exists
        if not os.path.exists(credentials_path):
            raise FileNotFoundError(f"Credentials file {credentials_path} not found. Please perform authentication.")
        
        # Authentication using the token file
        with open(credentials_path, 'rb') as token:
            credentials = pickle.load(token)

        # Create the API client
        service = build('sheets', 'v4', credentials=credentials)

        # Check if the CSV file exists
        if not os.path.exists(csv_file_path):
            raise FileNotFoundError(f"CSV file {csv_file_path} not found.")
        
        # Read the CSV file
        with open(csv_file_path, 'r', encoding='utf-8') as csvfile:
            reader = csv.reader(csvfile)
            values = list(reader)

        # Write the data to Google Sheets
        body = {
            'values': values
        }
        range_name = worksheet_name
        result = service.spreadsheets().values().update(
            spreadsheetId=spreadsheet_id,
            range=range_name,
            valueInputOption="RAW",
            body=body
        ).execute()

        print(f"Data from file {csv_file_path} successfully uploaded to Google Sheets.")
    except Exception as e:
        print(f"Error uploading data: {e}")

if __name__ == "__main__":
    # Console input
    print("Enter data to upload to Google Sheets:")

    # Path to the CSV file with default handling
    csv_file_path = input("Path to the CSV file (default 'output.csv', type 'd' for default): ").strip()
    if csv_file_path.lower() == 'd' or not csv_file_path:
        csv_file_path = 'output.csv'

    # Spreadsheet ID
    spreadsheet_id = input("Spreadsheet ID: ").strip()
    worksheet_name = input("Worksheet name (for example, 'Sheet1'): ").strip()

    # Path to the credentials token file with default handling
    credentials_path = input("Path to the credentials file (default 'token.pickle', type 'd' for default): ").strip()
    if credentials_path.lower() == 'd' or not credentials_path:
        credentials_path = 'token.pickle'

    # Call the function
    upload_csv_to_gsheet(csv_file_path, spreadsheet_id, worksheet_name, credentials_path)
