using Microsoft.AspNetCore.Identity.EntityFrameworkCore;
using Microsoft.EntityFrameworkCore;
using mike2.Models;
using ServiceProviderModel = mike2.Models.AppServiceProvider;

namespace mike2.Data
{
    public class ApplicationDbContext : IdentityDbContext<ApplicationUser>
    {
        public ApplicationDbContext(DbContextOptions<ApplicationDbContext> options)
            : base(options)
        {
        }

        public DbSet<ServiceProviderModel> ServiceProviders { get; set; }
        public DbSet<Service> Services { get; set; }
        public DbSet<Booking> Bookings { get; set; }
        public DbSet<Review> Reviews { get; set; }
        public DbSet<Notification> Notifications { get; set; }
        public DbSet<Availability> Availabilities { get; set; }

        protected override void OnModelCreating(ModelBuilder builder)
        {
            base.OnModelCreating(builder);

            // USER ↔ SERVICE_PROVIDER (1:1) عبر UserId (حسب الـ ERD: user_id FK UNIQUE)
            builder.Entity<ServiceProviderModel>()
                .HasOne(sp => sp.ApplicationUser)
                .WithOne(u => u.ServiceProvider)
                .HasForeignKey<ServiceProviderModel>(sp => sp.UserId)
                .OnDelete(DeleteBehavior.Cascade);

            builder.Entity<ServiceProviderModel>()
                .HasIndex(sp => sp.UserId)
                .IsUnique();

            // USER ↔ BOOKING (1:N) - Customer
            builder.Entity<Booking>()
                .HasOne(b => b.Customer)
                .WithMany(u => u.Bookings)
                .HasForeignKey(b => b.CustomerId)
                .OnDelete(DeleteBehavior.Restrict);

            // USER ↔ REVIEW (1:N) - Reviewer
            builder.Entity<Review>()
                .HasOne(r => r.Reviewer)
                .WithMany(u => u.Reviews)
                .HasForeignKey(r => r.ReviewerId)
                .OnDelete(DeleteBehavior.Restrict);

            // USER ↔ NOTIFICATION (1:N)
            builder.Entity<Notification>()
                .HasOne(n => n.User)
                .WithMany(u => u.Notifications)
                .HasForeignKey(n => n.UserId)
                .OnDelete(DeleteBehavior.Cascade);

            // SERVICE_PROVIDER ↔ SERVICE (1:N)
            builder.Entity<Service>()
                .HasOne(s => s.ServiceProvider)
                .WithMany(sp => sp.Services)
                .HasForeignKey(s => s.ServiceProviderId)
                .OnDelete(DeleteBehavior.Cascade);

            // SERVICE_PROVIDER ↔ AVAILABILITY (1:N)
            builder.Entity<Availability>()
                .HasOne(a => a.ServiceProvider)
                .WithMany(sp => sp.Availabilities)
                .HasForeignKey(a => a.ServiceProviderId)
                .OnDelete(DeleteBehavior.Cascade);

            // SERVICE_PROVIDER ↔ BOOKING (1:N)
            builder.Entity<Booking>()
                .HasOne(b => b.ServiceProvider)
                .WithMany(sp => sp.Bookings)
                .HasForeignKey(b => b.ServiceProviderId)
                .OnDelete(DeleteBehavior.Restrict);

            // SERVICE ↔ BOOKING (1:N)
            builder.Entity<Booking>()
                .HasOne(b => b.Service)
                .WithMany(s => s.Bookings)
                .HasForeignKey(b => b.ServiceId)
                .OnDelete(DeleteBehavior.Restrict);

            // AVAILABILITY ↔ BOOKING (1:1) عبر availability_id UNIQUE
            builder.Entity<Booking>()
            .HasOne(b => b.Availability)
            .WithOne(a => a.Booking)
            .HasForeignKey<Booking>(b => b.AvailabilityId)
            .OnDelete(DeleteBehavior.Restrict);


            // ضمان 1:1 على مستوى الـ DB بين AVAILABILITY و BOOKING (يسمح بـ null للحجوزات المرفوضة)
            builder.Entity<Booking>()
                .HasIndex(b => b.AvailabilityId)
                .IsUnique()
                .HasFilter("[AvailabilityId] IS NOT NULL"); // Allow null values

            // BOOKING ↔ REVIEW (1:1)
            builder.Entity<Review>()
                .HasOne(r => r.Booking)
                .WithOne(b => b.Review)
                .HasForeignKey<Review>(r => r.BookingId)
                .OnDelete(DeleteBehavior.Cascade);

            builder.Entity<Review>()
                .HasIndex(r => r.BookingId)
                .IsUnique();

            // BOOKING ↔ NOTIFICATION (1:N) – booking_id nullable
            builder.Entity<Notification>()
                .HasOne(n => n.Booking)
                .WithMany(b => b.Notifications)
                .HasForeignKey(n => n.BookingId)
                .OnDelete(DeleteBehavior.SetNull);
            builder.Entity<Service>()
           .Property(s => s.BasePrice)
           .HasColumnType("decimal(18,2)");
        }
    }
}
