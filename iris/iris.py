use di;                
SELECT                 
( "DI"                
) as portail,                
(                
SELECT COUNT(pdf.ID) AS nbPDF                
FROM PDF pdf                
LEFT JOIN Societe s ON pdf.IDSociete = s.ID                
WHERE pdf.PDFStatus="OK"                
AND pdf.Langue="En"                
AND s.StatutCom>0                
)
