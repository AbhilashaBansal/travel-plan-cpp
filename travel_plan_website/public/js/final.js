const doc = new PDFDocument();

// pipe the document to a blob
const stream = doc.pipe(blobStream());

onload = function(){
    let name = document.getElementById("name").textContent;
    let email = document.getElementById("email").textContent;
    let address = document.getElementById("address").textContent;
    let phone = document.getElementById("phone").textContent;
    let date = document.getElementById("date").textContent;
    let people = document.getElementById("people").textContent;
    let amt = document.getElementById("amt").textContent;
    let dest = document.getElementById("dest");

    doc.fontSize(20).text('Booking Slip', 100, 80);
    doc.moveDown();
    doc.fontSize(15).text(`${name}`);
    doc.moveDown();
    doc.fontSize(15).text(`${email}`);
    doc.moveDown();
    doc.fontSize(15).text(`${address}`);
    doc.moveDown();
    doc.fontSize(15).text(`${phone}`);
    doc.moveDown();
    doc.fontSize(15).text(`Destination/ Package: ${dest.textContent}`);
    
    doc.moveDown();
    doc.fontSize(15).text(`Date: ${date}`);
    doc.moveDown();
    doc.fontSize(15).text(`No of people: ${people}`);
    doc.moveDown();
    doc.fontSize(15).text(`Amount Payable: ${amt}`);
    doc.moveDown();
    doc.fontSize(15).text("Agency contact no: 9999000022");
    // finalize the PDF and end the stream
    doc.end();
    let iframe = document.getElementById("iframe");
    stream.on('finish', function() {
        iframe.src = stream.toBlobURL('application/pdf');
    });
};

