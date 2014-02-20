stepic_moor
===========

Recently, Professors Pavel Pevzner, Phillip Compeau and Nikolay Vyahhi
offered an online course on bioinformatics algorithm. Associated with
it, they posed serveral open research questions(
https://wiki.research.stepic.org/view/Main_Page ).  With viruses,
bacteria and archaea, DNA is circular. Where does replication begin?
This point is called the origin of replication.  Many of these open
problems seek to location the origin of relication.

# Finding Replication Origins in Draft Bacterial Genomes

You'll find the wiki for this problem here (
https://wiki.research.stepic.org/view/Finding_Replication_Origins_in_Draft_Bacterial_Genomes
). Basically, one is considering a new draft bacterial called TM6. The
goal is to find the origin of replication. There are data for two datasets. 

The seven largest contigs from the MDA2 dataset in the McLeana et al
paper is available on NCBI. The fetch_TM6SC1 function in tm6.py can be
used to retrieve it. Collectively this dataset is estimated to contain
about 91% of the expected genome for TM6.  

The wiki page provides access to a second dataset. It doesn't appear
to be one of the datasets referred to in the McLeana paper because
size of the longest contig doesn't match those reported in the paper.

