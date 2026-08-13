import os
import re
from flask import Flask, render_template, request, redirect, url_for, send_file
import qrcode

app = Flask(__name__)

STATIC_FOLDER = 'static'
QR_CODE_DIR = os.path.join(STATIC_FOLDER, 'qrcodes')
app.config['UPLOAD_FOLDER'] = QR_CODE_DIR

os.makedirs(app.config['UPLOAD_FOLDER'], exist_ok=True)

# You can copy your validation function from Module 1 here (Not Required).
def validate_linkedin_url(url):
    # --- YOUR VALIDATION FUNCTION FROM MODULE 1 GOES HERE ---
    url_pattern = re.compile(
        r'^((http|https)://)?'
        r'(www\.)?'
        r'linkedin\.com/'
        r'(company|in)/.*'
    )
    return url_pattern.fullmatch(url) != None


@app.route('/', methods=['GET', 'POST'])
def index():
    # --- COPY YOUR COMPLETE LOGIC FOR THE 'index' ROUTE FROM MODULE 1 HERE ---
    
    # Dummy implementation for now:
    if request.method == 'POST':
        # This is where your real code should go.
        url = request.form['linkedin_url']
        
        # Step 1: Validate the URL
        valid_qr = validate_linkedin_url(url)

        if(valid_qr == False):
            return render_template('index.html', error = 'Invalid Linkedin URL')

        # Step 2: If valid, generate the QR code
        qr = qrcode.make(url)
        filename = os.path.join(app.config['UPLOAD_FOLDER'],'linkedin_profile_qr.png')
        qr.save(filename)

        # Step 3: Redirect to the new QR display page
        return redirect(url_for('qr_display'))
        
    # For a GET request, just show the home page without any error    
    return render_template('index.html')

@app.route('/qr-code')
def qr_display():
    return render_template('qr_display.html')


@app.route('/download/<filename>')
def download_qr(filename):
    """
    This is the new route you must implement.
    It should send the requested file for download.
    """
    filepath = os.path.join(app.config['UPLOAD_FOLDER'], filename)
    return send_file(filepath, as_attachment=True)
    
     # Replace this with your implementation


if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000, debug=True)