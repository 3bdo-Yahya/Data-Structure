import os

folder_path = r"d:\C++\Data Structure"

for filename in os.listdir(folder_path):

    if " " in filename:
        new_name = filename.replace(" ", "-")
    
    # if filename[0].isdigit():
        
        # new_name = "DS_" + filename
        
        # Get full paths
        old_file = os.path.join(folder_path, filename)
        new_file = os.path.join(folder_path, new_name)

        os.rename(old_file, new_file)
        print(f'Renamed: "{filename}" to "{new_name}"')

print("Renaming complete!")